#ifndef BOOKDATASTORE_H_INCLUDED
#define BOOKDATASTORE_H_INCLUDED

#include "dataStoreStructs.h"

void initBookDataStore(struct BookDataStore bookDataStore);
void addBookToDataStore(struct Book b, struct BookDataStore bookDataStore);
void removeBookFromDataStore(int bookID, struct BookDataStore bookDataStore);
struct Book* searchBooksInDataStore(int byBookName, char name[], int count, struct BookDataStore bookDataStore);

#endif
