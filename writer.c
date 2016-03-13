#include <string.h>

#include "writer.h"
#include "globalVars.h"

struct Writer newWriter(char name[], char username[], char password[]){
    struct Writer writer;
    strcpy(name, writer.name);
    strcpy(username, writer.username);
    strcpy(password, writer.password);
    return writer;
}

int getDues(struct Writer *writer){
    // A Lannister always pays his debts! :)
    int ret = makeTransaction(writer->dues);
    if(ret) writer->dues = 0;
    return ret;
}
