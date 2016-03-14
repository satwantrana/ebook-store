#include <string.h>

#include "customerDataStore.h"

struct CustomerDataStore newCustomerDataStore(){
    struct CustomerDataStore customerDataStore;
    customerDataStore.size = 0;
    memset(customerDataStore.taken,0,sizeof customerDataStore.taken);
    return customerDataStore;
}

void addCustomerToDataStore(struct Customer *c, struct CustomerDataStore *customerDataStore){
    for(int i=0;i<maxArraySize;i++) if(!customerDataStore->taken[i]){
        c->id = i;
        customerDataStore->customers[i] = c;
        customerDataStore->taken[i] = 1;
        customerDataStore->size++;
        break;
    }
}

void removeCustomerFromDataStore(struct Customer* c, struct CustomerDataStore *customerDataStore){
    customerDataStore->taken[c->id] = 0;
    customerDataStore->size--;
}
