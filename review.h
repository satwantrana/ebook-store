#ifndef REVIEW_H_INCLUDED
#define REVIEW_H_INCLUDED

#include "globalVars.h"

struct Review {
  int customerID;
  int bookID;
  int rating; // out of 5
  char body[maxArraySize];
};

struct Review newReview(int customerID, int bookID, int rating, char body[]);

#endif
