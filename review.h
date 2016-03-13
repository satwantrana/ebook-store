#ifndef REVIEW_H_INCLUDED
#define REVIEW_H_INCLUDED

struct Review {
  int customerID;
  int rating; // out of 5
  char body[1000];
};

struct Review newReview(int customerID, int rating, char body[]);

#endif
