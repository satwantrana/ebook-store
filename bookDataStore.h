#ifndef BOOKDATASTORE_H_INCLUDED
#define BOOKDATASTORE_H_INCLUDED

#include "globalVars.h"
#include "book.h"

struct BookDataStore {
    int size;
    struct Book books[maxDataStoreSize];
    int taken[maxDataStoreSize];
};

struct BookDataStore newBookDataStore();
void addBookToDataStore(struct Book b, struct BookDataStore bookDataStore);
void removeBookFromDataStore(int bookID, struct BookDataStore bookDataStore);
struct Book* searchBooksInDataStore(int byBookName, char name[], int count, struct BookDataStore bookDataStore);
#endif
