#include <stdlib.h>

#include "eBookStore.h"

struct EBookStore newEBookStore(){
    struct EBookStore eBookStore;
    eBookStore.admin = newAdmin("admin", "password");
    eBookStore.bookDataStore = newBookDataStore();
    eBookStore.customerDataStore = newCustomerDataStore();
    eBookStore.writerDataStore = newWriterDataStore();
    return eBookStore;
}

void assignSimilarBooks(struct Book* b, struct EBookStore *eBookStore){
    int sz = 0;
    for(int i=0;i<eBookStore->bookDataStore.size && sz<3;i++)
        if(i != b->id && eBookStore->bookDataStore.taken[i] &&
            eBookStore->bookDataStore.books[i]->writerID == b->writerID &&
                eBookStore->bookDataStore.books[i]->authorized){
                    b->similarBooks[sz++] = eBookStore->bookDataStore.books[i]->id;
                }
    b->similarBookCount = sz;
}

int authorizeBook(struct Book *b, struct EBookStore *eBookStore){
    // Authorize all the books! :)
    b->authorized = 1;
    return 1;
}

int deAuthorizeBook(struct Book* b, struct EBookStore *eBookStore){
    // Authorize all the books! :)
    b->authorized = 0;
    return 1;
}

int publishBook(struct Book* b, struct EBookStore *eBookStore){
    addBookToDataStore(b, &eBookStore->bookDataStore);
    struct Writer *w = eBookStore->writerDataStore.writers[b->writerID];
    w->bookIDs[w->bookCount++] = b->id;
    return authorizeBook(b, eBookStore);
}

int dePublishBook(struct Book *b, struct EBookStore *eBookStore) {
    return deAuthorizeBook(b, eBookStore);
}

struct Book buyBook(struct Book *b, struct Customer *c, struct EBookStore *eBookStore){
    int bookPrice = b->price;
    if(!b->authorized || !getPayment(c, bookPrice)){
        b->id = -1;
    } else {
        c->bookIDs[c->bookCount++] = b->id;
        struct Writer *w = eBookStore->writerDataStore.writers[b->writerID];
        w->dues += bookPrice;
    }
    return *b;
}

void addReview(struct Book *b, struct Customer *c, int rating, char review[], struct EBookStore *eBookStore){
    struct Review r = newReview(c->id, b->id, rating, review);
    c->reviews[c->reviewCount++] = &r;
    b->reviews[b->reviewCount++] = &r;
    b->ratingSum += rating;
}

int reviewCompareFunction(const void* a, const void* b){
    return (*(struct Review*)b).rating - (*(struct Review*)a).rating;
}

struct Book** getBookRecommendations(struct Customer *c, int count, struct EBookStore *eBookStore){
    struct Review* reviews[maxArraySize];
    for(int i=0;i<c->reviewCount;i++) reviews[i] = c->reviews[i];
    qsort(reviews, c->reviewCount, sizeof reviews[0], reviewCompareFunction);
    static struct Book* ret[maxArraySize];
    int j;
    for(int i=0,j=0;i<c->reviewCount && j<count;i++){
        struct Book *b = eBookStore->bookDataStore.books[reviews[i]->bookID];
        if(b->authorized) for(int k=0;k<b->similarBookCount && j<count;k++){
            struct Book *bb = eBookStore->bookDataStore.books[b->similarBooks[j]];
            if(bb->authorized) ret[j++] = bb;
        }
    }
    if(j<maxArraySize) ret[j]->id = -1;
    return ret;
}

void addWriter(struct Writer* w, struct EBookStore *eBookStore){
    addWriterToDataStore(w, &eBookStore->writerDataStore);
}
