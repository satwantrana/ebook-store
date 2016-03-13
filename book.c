#include "book.h"

double getAverageRating(Book b){
    return (double)b.sumRating/(double)b.countRating;
}
