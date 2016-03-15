#include <string.h>
#include <stdlib.h>
#include "eBookStore.h"

struct EBookStore eBookStore;

void customerBookSearchPage(struct Customer* c){
    printf("Enter book title: ");
    char *bookName; size_t numBytes = maxArraySize;
    bookName = (char *)malloc(numBytes+1);
    scanf("\n");
    getline(&bookName, &numBytes, stdin);
    if(bookName[strlen(bookName)-1] == '\n') bookName[strlen(bookName)-1] = '\0';
    printf("Searching for books with the title '%s'\n", bookName);
    struct Book* searchResult = searchBooksInDataStore(1, "Angels and Demons", 1, &eBookStore.bookDataStore)[0];
    if(searchResult->id >= 0){
        printf("Found book with the name %s by the author %s\n", searchResult->title, searchResult->author);
        printf("Its summary is, %s\n\n", searchResult->summary);

        int n = 0;
        printf("Input 1 to buy book\n");
        printf("Input -1 to go back\n");
        scanf("%d", &n);
        if(n == 1){
            buyBook(searchResult, c, &eBookStore);
            printf("Book bought :)\n");
        }
    } else {
        printf("Sorry, no such book in our database\n");
    }
    printf("Returning to customer home page\n");
}

void customerBookRecommendationsPage(struct Customer* c){
    if(!c->bookCount) printf("Buy some books to get recommendations\n");
    else {
        struct Book* readBook = eBookStore.bookDataStore.books[c->bookIDs[0]];
        // struct Book* res = getBookRecommendations(c, 1, &eBookStore)[0];
        assignSimilarBooks(readBook, &eBookStore);
        struct Book *similarBook = eBookStore.bookDataStore.books[readBook->similarBooks[0]];
        printf("Based on your usage, you should buy the book %s by the author %s\n", similarBook->title, similarBook->author);
    }
    printf("Returning to customer home page\n");
}

void customerHomePage(struct Customer* c){
    int n = 0;
    printf("Welcome to your home page %s!\n", c->username);
    while(n != -1){
        printf("Input 1 to search for a book\n");
        printf("Input 2 to get a book recommendation\n");
        printf("Input -1 to exit the system\n");
        scanf("%d", &n);
        if(n == 1) customerBookSearchPage(c);
        else if(n == 2) customerBookRecommendationsPage(c);
    }
}

void signInCustomer(){
    printf("Enter your customer id: ");
    int customerID;
    scanf("%d",&customerID);
    printf("Enter your password: ");
    char password[maxArraySize];
    scanf("%s", password);
    if(eBookStore.customerDataStore.taken[customerID] &&
        strcmp(eBookStore.customerDataStore.customers[customerID]->password, password) == 0){
            customerHomePage(eBookStore.customerDataStore.customers[customerID]);
        } else {
            printf("Invalid login\n");
        }
    printf("Returning to main page\n");
}

void writerHomePage(struct Writer *w){
    printf("Welcome to your home page %s!\n", w->username);
    printf("We owe you Rs. %f only\n", w->dues);
    int n = 0;
    while(n != -1){
        printf("Input 1 to get paid\n");
        printf("Input -1 to exit\n");
        scanf("%d", &n);
        if(n == 1){
            getDues(w);
            printf("Payment done, we owe you Rs. %f only\n", w->dues);
        }
        else if(n == -1) break;
    }
}

void signInWriter(){
    printf("Enter your writer id: ");
    int writerID;
    scanf("%d",&writerID);
    printf("Enter your password: ");
    char password[maxArraySize];
    scanf("%s", password);
    if(eBookStore.writerDataStore.taken[writerID] &&
        strcmp(eBookStore.writerDataStore.writers[writerID]->password, password) == 0){
            struct Writer *w = eBookStore.writerDataStore.writers[writerID];
            writerHomePage(w);
        } else {
            printf("Invalid login\n");
        }
    printf("Returning to main page\n");
}

void adminHomePage(){
    printf("Welcome to the admin home page!\n");
    int n = 0;
    while(n != -1){
        printf("Input 1 to print book database\n");
        printf("Input -1 to exit\n");
        scanf("%d", &n);
        if(n == 1){
            printBookDataStore(&eBookStore.bookDataStore);
        }
        else if(n == -1) break;
    }
}

void signInAdmin(){
    printf("Enter your username: ");
    char username[maxArraySize];
    scanf("%s", username);
    printf("Enter your password: ");
    char password[maxArraySize];
    scanf("%s", password);
    if(strcmp(eBookStore.admin.username, username) == 0 &&
        strcmp(eBookStore.admin.password, password) == 0){
            adminHomePage();
        } else {
            printf("Invalid login\n");
        }
    printf("Returning to main page\n");
}

void acceptQueries(){
    int n = 0;
    while(n != -1){
        printf("Welcome to our ebook store\n");
        printf("Input 1 to sign in to a writer account\n");
        printf("Input 2 to sign in to a customer account\n");
        printf("Input 3 to sign in to the admin account\n");
        printf("Input -1 to exit the system\n");
        scanf("%d", &n);
        if(n == 1) signInWriter();
        else if(n == 2) signInCustomer();
        else if(n == 3) signInAdmin();
        else if(n == -1) break;
    }
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
    struct Customer robertLangdon = newCustomer("Robert", "password");
    addCustomerToDataStore(&robertLangdon, &eBookStore.customerDataStore);
    printf("Created customer account for Robert Langdon with user id %d\n\n", robertLangdon.id);

    printf("Searching for books with the title 'Angels and Demons'\n");
    struct Book* searchResult = searchBooksInDataStore(1, "Angels and Demons", 1, &eBookStore.bookDataStore)[0];
    printf("Found one book with the name %s by the author %s\n", searchResult->title, searchResult->author);
    printf("Its summary is, %s\n\n", searchResult->summary);

    printf("Submitting an excellent review for %s from user name %s\n", searchResult->title, robertLangdon.username);
    addReview(searchResult, &robertLangdon, 5, "Awesome read! :)", &eBookStore);
    printf("Fetching all reviews for %s,\n\n", searchResult->title);

    acceptQueries();
}

void initEverything(){
    printf("Creating a new ebook store\n");
    eBookStore = newEBookStore();
    printf("Created a new ebook store\n\n");
}

int main() {
    setbuf(stdout, NULL);
    initEverything();
    doSomeStuff();
    return 0;
}
