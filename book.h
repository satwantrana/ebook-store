#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "review.h"

struct Book {
   char title[50];
   char author[50];
   char summary[1000];
   char content[1000];
   int id;
   int writerID;
   int authorized;
   int similarBooks[3];
   int similarBookCount;
   int price; // in rupees
   struct Review reviews[10];
   int ratingSum;
   int ratingCount;
};

struct Book newBook(char title[], char author[], char summary[], char content[], int writerID, int price);
double getAverageRating(struct Book b);

#endif
