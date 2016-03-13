#ifndef REVIEW_H_INCLUDED
#define REVIEW_H_INCLUDED

struct Review {
  char customerName;
  int id;
  int rating; // out of 5
  char review[1000];
};

#endif
