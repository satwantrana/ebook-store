#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include "review.h"

struct Customer {
  int  id;
  char username[50];
  char password[8];
  int bookCount;
  int  bookIds[100];// ids of books purchased
  int reviewCount;
  struct Review reviews[100];
};

struct Customer newCustomer(char username[], char password[]);

#endif
