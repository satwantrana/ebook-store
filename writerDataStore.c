#include "WriterDataStore.h"

void addWriterToDataStore(struct Writer w, struct WriterDataStore writerDataStore){
    for(int i=0;i<writerDataStore.size;i++) if(!writerDataStore.taken[i]){
        w.id = i;
        break;
    }
    writerDataStore.writers[w.id] = w;
}

void removeWriterFromDataStore(int writerID, struct WriterDataStore writerDataStore){
    writerDataStore.taken[writerID] = 0;
}

struct Writer* searchWritersInDataStore(char name[], int count, struct WriterDataStore writerDataStore){
    static struct Writer writers[maxReturnSize]; int sz = 0;
    for(int i=0;i<writerDataStore.size && sz<count;i++){
        if(writerDataStore.writers[i].name == name) writers[sz++] = writerDataStore.writers[i];
    }
    return writers;
}
