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
struct Book buyBook(int bookID, int customerID, struct EBookStore eBookStore);
int authorizeBook(int bookID, struct EBookStore eBookStore);
void assignSimilarBooks(int bookID, struct EBookStore eBookStore);
void addReview(int bookID, int customerID, int rating, char review[], struct EBookStore eBookStore);
int publishBook(char title[], char author[], char summary[], char content[], int writerID, int price, struct EBookStore eBookStore);
struct Book* getBookRecommendations(int customerID, int count, struct EBookStore eBookStore);
#endif
