#include <string.h>

#include "customer.h"

struct Customer newCustomer(char username[], char password[]){
    struct Customer customer;
    customer.id = -1; customer.bookCount = 0; customer.reviewCount = 0;
    strcpy(username, customer.username);
    strcpy(password, customer.password);
    return customer;
}
