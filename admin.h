#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "bookDataStore.h"
#include "customerDataStore.h"
#include "writerDataStore.h"

struct Admin {
  char username[50];
  char password[8];
  struct BookDataStore bookDataStore;
  // struct CustomerDataStore customerDataStore;
  struct WriterDataStore writerDataStore;
};

struct Admin newAdmin(char username[], char password[]);
#endif
