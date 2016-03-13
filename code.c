enum  Format {pdf,kindle} ;


struct Review {
  char customer_name;
  int book_id;
  int rating; // out of 5
  char  review[1000];
};

struct Book {
   char  title[50];
   char  author[50];
   char  summary[1000];
   int   book_id;
   int   writer_id;
   enum  Format type;
   int   similar_books[3];
   double avg_rating;
   struct Review reviews[10];
};

struct Writer {
   char  name[50];
   int  BookIds[50];//ids of books authored
   int   writer_id;
   double Dues;
   char username[50];
   char password[8];
};

struct Customer {
  int  cust_id;
  char username[50];
  char password[8];
  int  BookIds[100];// ids of books purchased
  struct Review reviews[100];
};

struct Admin {
char username[50];
char password[8];
};

int* getRecommendations(struct Review reviews[]) {
    while ()
   };
void displayRecommendations(int bookids[]) {
};

int main() {

return 0;}
