#include <string.h>

#include "review.h"

struct Review newReview(int customerID, int rating, char body[]){
    struct Review review;
    review.customerID = customerID; review.rating = rating;
    strcpy(body, review.body);
    return review;
}
