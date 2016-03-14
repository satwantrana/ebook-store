#include <string.h>

#include "WriterDataStore.h"

struct WriterDataStore newWriterDataStore(){
    struct WriterDataStore writerDataStore;
    writerDataStore.size = 0;
    memset(writerDataStore.taken,0,sizeof writerDataStore.taken);
    return writerDataStore;
}

void addWriterToDataStore(struct Writer *w, struct WriterDataStore *writerDataStore){
    for(int i=0;i<maxArraySize;i++) if(!writerDataStore->taken[i]){
        w->id = i;
        writerDataStore->writers[i] = w;
        writerDataStore->taken[i] = 1;
        writerDataStore->size++;
        break;
    }
}

void removeWriterFromDataStore(int writerID, struct WriterDataStore *writerDataStore){
    writerDataStore->taken[writerID] = 0;
    writerDataStore->size--;
}

struct Writer** searchWritersInDataStore(char name[], int count, struct WriterDataStore *writerDataStore){
    static struct Writer* writers[maxArraySize]; int sz = 0;
    for(int i=0;i<writerDataStore->size && sz<count;i++){
        if(writerDataStore->writers[i]->name == name) writers[sz++] = writerDataStore->writers[i];
    }
    return writers;
}
