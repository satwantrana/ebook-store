#ifndef WRITERDATASTORE_H_INCLUDED
#define WRITERDATASTORE_H_INCLUDED

#include "dataStoreStructs.h"

void addWriterToDataStore(struct Writer b);
void removeBookFromDataStore(int bookID);
Book* searchBooksInDataStore(bool byBookName, char name[], int count);

#endif
