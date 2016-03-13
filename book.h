#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "review.h"

enum Format {
    pdf,
    kindle
};

struct Book {
   char  title[50];
   char  author[50];
   char  summary[1000];
   int   id;
   int   writerID;
   enum  Format type;
   int   similarBooks[3];
   int   sumRating;
   int   countRating;
   int price; // in rupees
   struct Review reviews[10];
};

double getAverageRating(struct Book b);

#endif
