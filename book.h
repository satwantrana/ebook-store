#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "globalVars.h"
#include "review.h"

struct Book {
   char title[maxArraySize];
   char author[maxArraySize];
   char summary[maxArraySize];
   char content[maxArraySize];
   int id;
   int writerID;
   int authorized;
   int similarBooks[maxArraySize];
   int similarBookCount;
   int price; // in rupees
   struct Review* reviews[maxArraySize];
   int reviewCount;
   int ratingSum;
};

struct Book dummyBook();
struct Book newBook(char title[], char author[], char summary[], char content[], int writerID, int price);
double getAverageRating(struct Book *b);

#endif
