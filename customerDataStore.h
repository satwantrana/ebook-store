#ifndef CUSTOMERDATASTORE_H_INCLUDED
#define CUSTOMERDATASTORE_H_INCLUDED

#include "globalVars.h"
#include "customer.h"

struct CustomerDataStore {
    int size;
    struct Customer* customers[maxArraySize];
    int taken[maxArraySize];
};

struct CustomerDataStore newCustomerDataStore();
void addCustomerToDataStore(struct Customer* c, struct CustomerDataStore *customerDataStore);
void removeCustomerFromDataStore(struct Customer* c, struct CustomerDataStore *customerDataStore);
#endif
