#include <string.h>

#include "admin.h"

struct Admin newAdmin(char username[], char password[]){
    struct Admin admin;
    strcpy(admin.username, username);
    strcpy(admin.password, password);
    return admin;
}
