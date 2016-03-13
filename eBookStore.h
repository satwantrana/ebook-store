#ifndef EBOOKSTORE_H_INCLUDED
#define EBOOKSTORE_H_INCLUDED

#include "admin.h"
#include "bookDataStore.h"
#include "customerDataStore.h"
#include "writerDataStore.h"

struct EBookStore {
    struct Admin admin;
    struct BookDataStore bookDataStore;
    struct CustomerDataStore customerDataStore;
    struct WriterDataStore writerDataStore;
};

struct EBookStore newEBookStore();
struct Book buyBook(int bookID, int customerID, struct EBookStore eBookStore);
void authorizeBooksInDataStore(struct Admin admin, struct BookDataStore bookDataStore);
void addReview(int bookID, int customerID, int rating, char review[], struct EBookStore eBookStore);
#endif
