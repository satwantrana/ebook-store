#include <string.h>

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

struct Book* searchBooksInDataStore(int byBookName, char name[], int count, struct BookDataStore bookDataStore){
    static struct Book books[maxReturnSize]; int sz = 0;
    for(int i=0;i<bookDataStore.size && sz<count;i++){
        if((byBookName && bookDataStore.books[i].title == name) ||
                (!byBookName && bookDataStore.books[i].author == name)) books[sz++] = bookDataStore.books[i];
    }
    return books;
}
