#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int bookID;
	char title[100];
	char author[50];
	int year;
	float price;
} Book;

#define MAX 100
Book books[MAX];
int N = 0; 

void loadBookData();
void saveBookData();
void inputBookData();
void displayBookData();
void findBookID();
void calculateTotalValue();

int main() {
	int choice;

	loadBookData();

	while(1) {
		printf("\nLibrary Management System\n");
		printf("1. Add a Book\n");
		printf("2. Display All Books\n");
		printf("3. Search for Book by ID\n");
		printf("4. Calculate Total Value of Books\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				inputBookData();
				saveBookData();
				break;
			case 2:
				displayBookData();
				break;
			case 3:
				findBookID();
				break;
			case 4:
				calculateTotalValue();
				break;
			case 5:
				printf("Saving Data to books.dat and Existing...\n");
				saveBookData();
				return 0;
			default:
				printf("Invalid input. please try again.\n");
		}
	}

	return 0;
}

void loadBookData() {
	FILE *file = fopen("task5/books.dat", "rb");
	if (file == NULL) {
		perror("Error! Could not open file.");
		return;
	}
	N = fread(books, sizeof(Book), MAX, file);
	fclose(file);
}

void saveBookData() {
	FILE *file = fopen("task5/books.dat", "wb");
	if (file == NULL) {
		perror("Error! Could not open file.");
		return;
	}

	fwrite(books, sizeof(Book), N, file);
	fclose(file);
}

void inputBookData() {
	if (N >= MAX) {
		printf("Your library is full. Cannot add new books.\n");
		return;
	}

	Book newBook;
	printf("Enter book ID: ");
	scanf("%d", &newBook.bookID);

	printf("Enter book title: ");
	getchar();
	fgets(newBook.title, sizeof(newBook.title), stdin);
	newBook.title[strcspn(newBook.title, "\n")] = '\0';
	
	printf("Enter book author: ");
	fgets(newBook.author, sizeof(newBook.author), stdin);
	newBook.author[strcspn(newBook.author, "\n")] = '\0';			
	
	printf("Enter publication year: ");
	scanf("%d", &newBook.year);
	
	printf("Enter book price (SAR): ");
	scanf("%f", &newBook.price);

	books[N++] = newBook;
	printf("Book added to the library.\n");
}

void displayBookData() {
	if (N == 0) {
		printf("No books available. \n");
		return;
	}

	printf("\nBook Details:\n");
	for (int i = 0; i < N; i++) {
		printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n",
			books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
	}
}

void findBookID() {
	int id;
	printf("Enter book ID: ");
	scanf("%d", &id);

	for (int i = 0; i < N; i++) {
		if (books[i].bookID == id) {
			printf("Book found:\n");
			printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n", books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
		return;
		}
	}
	printf("No book with ID %d\n", id);
}

void calculateTotalValue() {
	float totalValue = 0;
	for (int i = 0; i < N; i++) {
		totalValue += books[i].price;
	}
	printf("Total value of the book(s): %.2f SAR\n", totalValue);
}
