#include "WriterDataStore.h"

void addBookToDataStore(struct Book b, BookDataStore bookDataStore){
    for(int i=0;i<bookDataStore.size;i++) if(!bookDataStore.taken[i]){
        b.id = i;
        break;
    }
    bookDataStore.books[b.id] = b;
}

void removeBookFromDataStore(int bookID, BookDataStore bookDataStore){
    bookDataStore.taken[bookID] = 0;
}

const int maxReturnSize = 10;
Book* searchBooksInDataStore(bool byBookName, char name[], BookDataStore bookDataStore){
    Book books[maxReturnSize]; int sz = 0;
    for(int i=0;i<bookDataStore.size && sz<count;i++){
        if((byBookName && bookDataStore[i].title == name) ||
                (!byBookName && bookDataStore[i].author == name)) books[sz++] = bookDataStore[i];
    }
    return books;
}
