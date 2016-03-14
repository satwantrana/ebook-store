#include <string.h>

#include "bookDataStore.h"

struct BookDataStore newBookDataStore(){
    struct BookDataStore bookDataStore;
    bookDataStore.size = 0;
    memset(bookDataStore.taken,0,sizeof bookDataStore.taken);
    return bookDataStore;
}

void addBookToDataStore(struct Book *b, struct BookDataStore *bookDataStore){
    for(int i=0;i<maxArraySize;i++) if(!bookDataStore->taken[i]){
        b->id = i;
        bookDataStore->books[i] = b;
        bookDataStore->taken[i] = 1;
        bookDataStore->size++;
        break;
    }
}

void removeBookFromDataStore(struct Book *b, struct BookDataStore *bookDataStore){
    bookDataStore->taken[b->id] = 0;
    bookDataStore->size--;
}

struct Book** searchBooksInDataStore(bool byBookName, char name[], int count, struct BookDataStore *bookDataStore){
    static struct Book* books[maxArraySize]; int sz = 0;
    for(int i=0;i<maxArraySize && sz<count;i++) if(bookDataStore->taken[i]){
        char* title = bookDataStore->books[i]->title;
        char* author = bookDataStore->books[i]->author;
        if(bookDataStore->books[i]->authorized &&
            ((byBookName && strcmp(name, title) == 0) ||
                (!byBookName && strcmp(name, author) == 0)))
                    books[sz++] = bookDataStore->books[i];
    }
    return books;
}
