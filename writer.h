#ifndef WRITER_H_INCLUDED
#define WRITER_H_INCLUDED

#include "globalVars.h"

struct Writer {
   char  name[maxArraySize];
   int bookCount;
   int  bookIDs[maxArraySize];//ids of books authored
   int   id;
   double dues;
   char username[maxArraySize];
   char password[maxArraySize];
};

struct Writer newWriter(char name[], char username[], char password[]);
int getDues(struct Writer *writer);
#endif
