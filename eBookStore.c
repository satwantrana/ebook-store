#include "eBookStore.h"

struct EBookStore newEBookStore(){
    struct EBookStore eBookStore;
    eBookStore.admin = newAdmin("admin", "admin");
    eBookStore.bookDataStore = newBookDataStore();
    eBookStore.customerDataStore = newCustomerDataStore();
    eBookStore.writerDataStore = newWriterDataStore();
    return eBookStore;
}

struct Book buyBook(int bookID, int customerID, struct EBookStore eBookStore){
    struct Book *b = &eBookStore.bookDataStore.books[bookID];
    int bookPrice = b->price;
    struct Customer *c = &eBookStore.customerDataStore.customers[customerID];
    if(!getPayment(c, bookPrice)){
        b->id = -1;
    } else {
        c->bookIDs[c->bookCount++] = b->id;
        struct Writer *w = &eBookStore.writerDataStore.writers[b->writerID];
        w->dues += bookPrice;
    }
    return *b;
}

void authorizeBooksInDataStore(struct Admin admin, struct BookDataStore bookDataStore){
    for(int i=0;i<bookDataStore.size;i++)
        if(!bookDataStore.books[i].authorized) bookDataStore.books[i].authorized = 1;
}

void addReview(int bookID, int customerID, int rating, char review[], struct EBookStore eBookStore){
    struct Book *b = &eBookStore.bookDataStore.books[bookID];
    struct Customer *c = &eBookStore.customerDataStore.customers[customerID];
    struct Review r = newReview(c->id, rating, review);
    c->reviews[c->reviewCount++] = r;
    b->reviews[b->reviewCount++] = r;
    b->ratingSum += rating;
}
