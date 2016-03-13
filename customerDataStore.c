#include <string.h>

#include "customerDataStore.h"

struct CustomerDataStore newCustomerDataStore(){
    struct CustomerDataStore customerDataStore;
    customerDataStore.size = 0;
    memset(customerDataStore.taken,0,sizeof customerDataStore.taken);
    return customerDataStore;
}

void addCustomerToDataStore(struct Customer c, struct CustomerDataStore customerDataStore){
    for(int i=0;i<customerDataStore.size;i++) if(!customerDataStore.taken[i]){
        c.id = i;
        break;
    }
    customerDataStore.customers[c.id] = c;
}

void removeCustomerFromDataStore(int customerID, struct CustomerDataStore customerDataStore){
    customerDataStore.taken[customerID] = 0;
}
