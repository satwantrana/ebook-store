#include <string.h>

#include "eBookStore.h"

struct EBookStore eBookStore;
void initEverything(){
    printf("Creating a new ebook store\n");
    eBookStore = newEBookStore();
    printf("Created a new ebook store\n\n");
}

void doSomeStuff(){
    printf("Creating account for Dan Brown\n");
    struct Writer danBrown = newWriter(
        "Dan Brown",
        "danbrown",
        "password"
    );
    addWriter(&danBrown, &eBookStore);
    printf("Created account for Dan Brown with ID %d\n\n", danBrown.id);

    printf("Adding the book Angels and Demons\n");
    struct Book angelsAndDemons = newBook(
        "Angels and Demons",
        "Dan Brown",
        "Science and Mythology and Stuff",
        "In not so distant past...",
        danBrown.id,
        100
    );
    publishBook(&angelsAndDemons, &eBookStore);
    printf("Added the book Angels and Demons with ID %d\n\n", angelsAndDemons.id);

    printf("Adding the book Da Vinci Code\n");
    struct Book daVinciCode = newBook(
        "Da Vinci Code",
        "Dan Brown",
        "Its about the hipster Leo",
        "Once upon a time...",
        danBrown.id,
        100
    );
    publishBook(&daVinciCode, &eBookStore);
    printf("Added the book Da Vinci Code with ID %d\n\n", daVinciCode.id);

    printf("Books published by %s on our platform are,\n", danBrown.name);
    for(int i=0;i<danBrown.bookCount;i++){
        int bookID = danBrown.bookIDs[i];
        struct Book *b = eBookStore.bookDataStore.books[bookID];
        printf("#%d:\t%s\n", i+1, b->title);
    }
    printf("\n");

    printf("Finding books similar to %s\n", daVinciCode.title);
    assignSimilarBooks(&daVinciCode, &eBookStore);
    for(int i=0;i<daVinciCode.similarBookCount;i++){
        int bookID = daVinciCode.similarBooks[i];
        struct Book *b = eBookStore.bookDataStore.books[bookID];
        printf("#%d:\t%s\n", i+1, b->title);
    }
    printf("\n");

    printf("Creating customer account for Robert Langdon\n");
    struct Customer robertLangdon = newCustomer("robertlangdon", "password");
    printf("Created customer account for Robert Langdon\n\n");

    printf("Searching for books with the title 'Angels and Demons'\n");
    struct Book* searchResult = searchBooksInDataStore(1, "Angels and Demons", 1, &eBookStore.bookDataStore)[0];
    printf("Found one book with the name %s by the author %s\n", searchResult->title, searchResult->author);
    printf("Its summary is, %s\n\n", searchResult->summary);

    printf("Submitting an excellent review for %s from user name %s\n", searchResult->title, robertLangdon.username);
    addReview(searchResult, &robertLangdon, 5, "Awesome read! :)", &eBookStore);
    printf("Fetching all reviews for %s,\n", searchResult->title);
    for(int i=0;i<searchResult->reviewCount;i++){
        printf("#%d: Rating: %d Comments: %s\n", i+1, searchResult->reviews[i]->rating, searchResult->reviews[i]->body);
    }
    printf("Average rating of %s is %f\n\n", searchResult->title, getAverageRating(searchResult));

    printf("That's all for this demo folks! :)\n");
}

int main() {
    setbuf(stdout, NULL);
    initEverything();
    doSomeStuff();
    return 0;
}
