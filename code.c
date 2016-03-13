#include <stdio.h>
#include <string.h>

#include "book.h"
#include "bookDataStore.h"

// Defining datastores
struct BookDataStore bookDataStore;

int* getRecommendations(struct Review reviews[], int num) {
    static int ret[maxReturnSize];
    return ret;
};

void displayRecommendations(int bookids[], int num) {
};

void initEverything(){
    bookDataStore = newBookDataStore(bookDataStore);
}

int main() {
  return 0;
}
