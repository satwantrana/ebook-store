#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include "review.h"
#include "bookDataStore.h"

struct Customer {
  int  id;
  char username[maxArraySize];
  char password[maxArraySize];
  int bookCount;
  int  bookIDs[maxArraySize];// ids of books purchased
  int reviewCount;
  struct Review* reviews[maxArraySize];
};

struct Customer newCustomer(char username[], char password[]);
int getPayment(struct Customer *customer, int price);
#endif
