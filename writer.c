#include <string.h>

#include "writer.h"

struct Writer newWriter(char name[], char username[], char password[]){
    struct Writer writer;
    strcpy(name, writer.name);
    strcpy(username, writer.username);
    strcpy(password, writer.password);
    return writer;
}
