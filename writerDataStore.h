#ifndef WRITERDATASTORE_H_INCLUDED
#define WRITERDATASTORE_H_INCLUDED

#include "globalVars.h"
#include "writer.h"

struct WriterDataStore {
    int size;
    struct Writer* writers[maxArraySize];
    int taken[maxArraySize];
};

struct WriterDataStore newWriterDataStore();
void addWriterToDataStore(struct Writer *b, struct WriterDataStore *writerDataStore);
void removeWriterFromDataStore(int writerID, struct WriterDataStore *writerDataStore);
struct Writer** searchWritersInDataStore(char name[], int count, struct WriterDataStore *writerDataStore);

#endif
