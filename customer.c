#include <string.h>

#include "customer.h"
#include "globalVars.h"

struct Customer newCustomer(char username[], char password[]){
    struct Customer customer;
    customer.id = -1; customer.bookCount = 0; customer.reviewCount = 0;
    strcpy(username, customer.username);
    strcpy(password, customer.password);
    return customer;
}

int getPayment(struct Customer *customer, int price){
    // Money should not be seen as a necessity
    // Instead it should be seen as a resource
    // With money we can solve real life problems
    // Like this one! :)
    return makeTransaction(price);
}
