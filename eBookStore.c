#include <stdlib.h>

#include "eBookStore.h"

struct EBookStore newEBookStore(){
    struct EBookStore eBookStore;
    eBookStore.admin = newAdmin("admin", "admin");
    eBookStore.bookDataStore = newBookDataStore();
    eBookStore.customerDataStore = newCustomerDataStore();
    eBookStore.writerDataStore = newWriterDataStore();
    return eBookStore;
}

void assignSimilarBooks(int bookID, struct EBookStore eBookStore){
    int sz = 0;
    struct Book *b = &eBookStore.bookDataStore.books[bookID];
    for(int i=0;i<eBookStore.bookDataStore.size && sz<3;i++) if(i != bookID){
        if(eBookStore.bookDataStore.taken[i] &&
            eBookStore.bookDataStore.books[i].writerID == b->writerID &&
                eBookStore.bookDataStore.books[i].authorized)
             b->similarBooks[sz++] = eBookStore.bookDataStore.books[i].id;
    }
    b->similarBookCount = sz;
}

int authorizeBook(int bookID, struct EBookStore eBookStore){
    // Authorize all the books! :)
    eBookStore.bookDataStore.books[bookID].authorized = 1;
    return 1;
}

int deAuthorizeBook(int bookID, struct EBookStore eBookStore){
    // Authorize all the books! :)
    eBookStore.bookDataStore.books[bookID].authorized = 0;
    return 1;
}

int publishBook(char title[], char author[], char summary[], char content[], int writerID, int price, struct EBookStore eBookStore){
    struct Book b = newBook(title, author, summary, content, writerID, price);
    addBookToDataStore(b, eBookStore.bookDataStore);
    assignSimilarBooks(b.id, eBookStore);
    struct Writer *w = &eBookStore.writerDataStore.writers[writerID];
    w->bookIDs[w->bookCount++] = b.id;
    return authorizeBook(b.id, eBookStore);
}

int dePublishBook(int bookID, struct EBookStore eBookStore) {
    return deAuthorizeBook(bookID, eBookStore);
}

struct Book buyBook(int bookID, int customerID, struct EBookStore eBookStore){
    struct Book *b = &eBookStore.bookDataStore.books[bookID];
    int bookPrice = b->price;
    struct Customer *c = &eBookStore.customerDataStore.customers[customerID];
    if(!b->authorized || !getPayment(c, bookPrice)){
        b->id = -1;
    } else {
        c->bookIDs[c->bookCount++] = b->id;
        struct Writer *w = &eBookStore.writerDataStore.writers[b->writerID];
        w->dues += bookPrice;
    }
    return *b;
}

void addReview(int bookID, int customerID, int rating, char review[], struct EBookStore eBookStore){
    struct Book *b = &eBookStore.bookDataStore.books[bookID];
    struct Customer *c = &eBookStore.customerDataStore.customers[customerID];
    struct Review r = newReview(customerID, bookID, rating, review);
    c->reviews[c->reviewCount++] = r;
    b->reviews[b->reviewCount++] = r;
    b->ratingSum += rating;
}

int reviewCompareFunction(const void* a, const void* b){
    return (*(struct Review*)b).rating - (*(struct Review*)a).rating;
}

struct Book* getBookRecommendations(int customerID, int count, struct EBookStore eBookStore){
    struct Review reviews[maxReturnSize];
    struct Customer c = eBookStore.customerDataStore.customers[customerID];
    for(int i=0;i<c.reviewCount;i++) reviews[i] = c.reviews[i];
    qsort(reviews, c.reviewCount, sizeof reviews[0], reviewCompareFunction);
    static struct Book ret[maxReturnSize];
    int j;
    for(int i=0,j=0;i<c.reviewCount && j<count;i++){
        struct Book b = eBookStore.bookDataStore.books[reviews[i].bookID];
        if(b.authorized) for(int k=0;k<b.similarBookCount && j<count;k++){
            struct Book bb = eBookStore.bookDataStore.books[b.similarBooks[j]];
            if(bb.authorized) ret[j++] = bb;
        }
    }
    ret[j].id = -1;
    return ret;
}
