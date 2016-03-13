#include <string.h>

#include "bookDataStore.h"

struct BookDataStore newBookDataStore(){
    struct BookDataStore bookDataStore;
    bookDataStore.size = 0;
    memset(bookDataStore.taken,0,sizeof bookDataStore.taken);
    return bookDataStore;
}

void addBookToDataStore(struct Book b, struct BookDataStore bookDataStore){
    assignSimilarBooksFromDataStore(&b, bookDataStore);
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
        if(bookDataStore.books[i].authorized &&
            ((byBookName && bookDataStore.books[i].title == name) ||
                (!byBookName && bookDataStore.books[i].author == name)))
                    books[sz++] = bookDataStore.books[i];
    }
    return books;
}

void assignSimilarBooksFromDataStore(struct Book *b, struct BookDataStore bookDataStore){
    int sz = 0;
    for(int i=0;i<bookDataStore.size && sz<3;i++){
        if(bookDataStore.taken[i] && bookDataStore.books[i].writerID == b->writerID)
            b->similarBooks[sz++] = bookDataStore.books[i].id;
    }
    b->similarBookCount = sz;
}
