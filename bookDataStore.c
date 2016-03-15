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
        // printf("%d %s %s\n",
        //     bookDataStore->books[i]->id,
        //     bookDataStore->books[i]->title,
        //     bookDataStore->books[i]->author
        // );
        break;
    }
}

void printBookDataStore(struct BookDataStore *bookDataStore){
    printf("We currently have %d books in the system\n", bookDataStore->size);
    for(int i=0;i<maxArraySize;i++) if(bookDataStore->taken[i]){
        printf("#%d: '%s' by '%s'\n",
            bookDataStore->books[i]->id,
            bookDataStore->books[i]->title,
            bookDataStore->books[i]->author
        );
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
        // printf("%s %s\n", title, author);
        if(bookDataStore->books[i]->authorized &&
            ((byBookName && strcmp(name, title) == 0) ||
                (!byBookName && strcmp(name, author) == 0)))
                    books[sz++] = bookDataStore->books[i];
    }
    // printf("%d %s\n",sz, books[0]->title);
    struct Book dummy = dummyBook();
    books[sz] = &dummy;
    return books;
}
