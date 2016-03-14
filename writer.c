#include <string.h>

#include "writer.h"
#include "globalVars.h"

struct Writer newWriter(char name[], char username[], char password[]){
    struct Writer writer;
    writer.bookCount = 0; writer.id = -1; writer.dues= 0;
    strcpy(writer.name, name);
    strcpy(writer.username, username);
    strcpy(writer.password, password);
    return writer;
}

int getDues(struct Writer *writer){
    // A Lannister always pays his debts! :)
    int ret = makeTransaction(writer->dues);
    if(ret) writer->dues = 0;
    return ret;
}
