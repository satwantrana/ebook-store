#ifndef DATASTORESTRUCTS_H_INCLUDED
#define DATASTORESTRUCTS_H_INCLUDED

enum Format {
    pdf,
    kindle
};

struct Review {
  char customerName;
  int id;
  int rating; // out of 5
  char review[1000];
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

struct Writer {
   char  name[50];
   int  bookIDs[50];//ids of books authored
   int   id;
   double dues;
   char username[50];
   char password[8];
};

struct Customer {
  int  id;
  char username[50];
  char password[8];
  int  bookIds[100];// ids of books purchased
  struct Review reviews[100];
};

struct Admin {
  char username[50];
  char password[50];
};

const int maxDataStoreSize = 10000;
const int maxReturnSize = 10;

struct BookDataStore {
    int size;
    struct Book books[maxDataStoreSize];
    int taken[maxDataStoreSize];
};

struct WriterDataStore {
    int size;
    struct Writer writers[maxDataStoreSize];
    int taken[maxDataStoreSize];
};

#endif
