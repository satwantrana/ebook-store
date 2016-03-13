#include "bookDataStore.h"

void initBookDataStore(struct BookDataStore bookDataStore){
    bookDataStore.size = 0;
    memset(bookDataStore.taken,0,sizeof bookDataStore.taken);
}

void addBookToDataStore(struct Book b, struct BookDataStore bookDataStore){
    for(int i=0;i<bookDataStore.size;i++) if(!bookDataStore.taken[i]){
        b.id = i;
        break;
    }
    bookDataStore.books[b.id] = b;
}

void removeBookFromDataStore(int bookID, struct BookDataStore bookDataStore){
    bookDataStore.taken[bookID] = 0;
}

const int maxReturnSize = 10;
struct Book* searchBooksInDataStore(int byBookName, char name[], int count, struct BookDataStore bookDataStore){
    Book books[maxReturnSize]; int sz = 0;
    for(int i=0;i<bookDataStore.size && sz<count;i++){
        if((byBookName && bookDataStore[i].title == name) ||
                (!byBookName && bookDataStore[i].author == name)) books[sz++] = bookDataStore[i];
    }
    return books;
}
