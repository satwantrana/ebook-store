#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include "review.h"
#include "bookDataStore.h"

struct Customer {
  int  id;
  char username[50];
  char password[8];
  int bookCount;
  int  bookIDs[100];// ids of books purchased
  int reviewCount;
  struct Review reviews[100];
};

struct Customer newCustomer(char username[], char password[]);
int getPayment(struct Customer *customer, int price);
#endif
