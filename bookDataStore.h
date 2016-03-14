#ifndef BOOKDATASTORE_H_INCLUDED
#define BOOKDATASTORE_H_INCLUDED

#include "globalVars.h"
#include "book.h"

struct BookDataStore {
    int size;
    struct Book* books[maxArraySize];
    int taken[maxArraySize];
};

struct BookDataStore newBookDataStore();
void addBookToDataStore(struct Book *b, struct BookDataStore *bookDataStore);
void removeBookFromDataStore(struct Book* b, struct BookDataStore *bookDataStore);
struct Book** searchBooksInDataStore(bool byBookName, char name[], int count, struct BookDataStore *bookDataStore);
#endif
