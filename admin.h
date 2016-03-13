#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

struct Admin {
  char username[50];
  char password[8];
};

struct Admin newAdmin(char username[], char password[]);

#endif
