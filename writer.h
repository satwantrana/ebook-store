#ifndef WRITER_H_INCLUDED
#define WRITER_H_INCLUDED

struct Writer {
   char  name[50];
   int  bookIDs[50];//ids of books authored
   int   id;
   double dues;
   char username[50];
   char password[8];
};

#endif
