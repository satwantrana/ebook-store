#ifndef EBOOKSTORE_H_INCLUDED
#define EBOOKSTORE_H_INCLUDED

#include "admin.h"
#include "bookDataStore.h"
#include "customerDataStore.h"
#include "writerDataStore.h"

struct EBookStore {
    struct Admin admin;
    struct BookDataStore bookDataStore;
    struct CustomerDataStore customerDataStore;
    struct WriterDataStore writerDataStore;
};

struct EBookStore newEBookStore();
void addWriter(struct Writer* w, struct EBookStore *eBookStore);
int publishBook(struct Book* b, struct EBookStore *eBookStore);

void assignSimilarBooks(struct Book *b, struct EBookStore *eBookStore);
int authorizeBook(struct Book *b, struct EBookStore *eBookStore);

struct Book buyBook(struct Book *b, struct Customer *c, struct EBookStore *eBookStore);
void addReview(struct Book *b, struct Customer *c, int rating, char review[], struct EBookStore *eBookStore);
struct Book** getBookRecommendations(struct Customer *c, int count, struct EBookStore *eBookStore);
#endif
