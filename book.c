#include "book.h"
#include "string.h"

struct Book newBook(char title[], char author[], char summary[], char content[], int writerID, int price){
    struct Book book;
    strcpy(book.title, title); strcpy(book.author, author);
    strcpy(book.summary, summary); strcpy(book.content, content);
    book.writerID = writerID; book.price = price;
    book.id = -1; book.authorized = 0; book.ratingSum = 0; book.reviewCount = 0;
    book.similarBookCount = 0;
    return book;
}

double getAverageRating(struct Book *b){
    if(b->reviewCount == 0) return 0;
    return (double)b->ratingSum/(double)b->reviewCount;
}
