#include "book.h"

double getAverageRating(struct Book b){
    return (double)b.sumRating/(double)b.countRating;
}
