#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include "review.h"

struct Customer {
  int  id;
  char username[50];
  char password[8];
  int  bookIds[100];// ids of books purchased
  struct Review reviews[100];
};

#endif
