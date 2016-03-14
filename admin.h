#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "globalVars.h"

struct Admin {
  char username[maxArraySize];
  char password[maxArraySize];
};

struct Admin newAdmin(char username[], char password[]);
#endif
