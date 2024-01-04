#include <stdio.h>

#include <string.h>

#include <conio.h>

#include <stdlib.h>

char ch = 178;

struct Book {
    char title[100];
    char author[50];
    float price;
    int quantity;
};

struct Book books[100];
int bookCount = 0;
struct PurchasedBook {
    char title[100];
    char author[50];
    float price;
    int quantity;
};

struct PurchasedBook purchasedBooks[100];
int purchasedBookCount = 0;

void heading() {
    printf("\n");
    for (int i = 1; i <= 26; i++)
        printf("%c", ch);
    printf(" Book Shop Mangement System ");
    for (int i = 1; i <= 26; i++)
        printf("%c", ch);
}

void displayMenu() {
    printf("\n\n %c%c 1. Add book", ch, ch);
    printf("\n\n %c%c 2. List book", ch, ch);
    printf("\n\n %c%c 3. Edit book", ch, ch);
    printf("\n\n %c%c 4. Search book", ch, ch);
    printf("\n\n %c%c 5. Purchase book", ch, ch);
    printf("\n\n %c%c 6. Exit\n\n", ch, ch);
}

void addBook() {
    system("cls");
    heading();
    system("COLOR D5");
    if (bookCount < 100) {
        printf("\n\nEnter book title: ");
        scanf(" %[^\n]s", books[bookCount].title);
        printf("\nEnter author name: ");
        scanf(" %[^\n]s", books[bookCount].author);
        printf("\nEnter price: ");
        scanf("%f", &books[bookCount].price);
        printf("\nEnter quantity: ");
        scanf("%d", &books[bookCount].quantity);
        bookCount++;
        printf("\n\nBook added successfully!\n");
    } else {
        printf("Maximum book limit reached!\n");
    }
}

void listBooks() {
    system("cls");
    heading();
    system("COLOR E8");
    if (bookCount == 0) {
        strcpy(books[bookCount].title, "C++ Program");
        strcpy(books[bookCount].author, "Devid ");
        books[bookCount].price = 14.50;
        books[bookCount].quantity = 1200;
        bookCount++;
        strcpy(books[bookCount].title, "Data Structure And Algorithm");
        strcpy(books[bookCount].author, "Subeen");
        books[bookCount].price = 15.40;
        books[bookCount].quantity = 1700;
        bookCount++;
    }

    if (bookCount > 0) {
        printf("\n\nList of books:\n");
        for (int i = 0; i < bookCount; i++) {
            printf("%d. Title: %s, Author: %s, Price: $%.2f, Quantity: %d\n\n", i + 1, books[i].title, books[i].author, books[i].price, books[i].quantity);
        }
    } else {
        printf("No books available!!!\n");
    }
}

void editBook() {
    system("cls");
    heading();
    system("COLOR A5");
    int bookIndex;
    printf("\n\nEnter the book number to edit: ");
    scanf("%d", &bookIndex);
    if (bookIndex > 0 && bookIndex <= bookCount) {
        printf("\n\nEnter new title: ");
        scanf(" %[^\n]s", books[bookIndex - 1].title);
        printf("\n\nEnter new author name: ");
        scanf(" %[^\n]s", books[bookIndex - 1].author);
        printf("\n\nEnter new price: ");
        scanf("%f", &books[bookIndex - 1].price);
        printf("\n\nEnter new quantity: ");
        scanf("%d", &books[bookIndex - 1].quantity);
        printf("\n\nBook details updated successfully!\n");
    } else {
        printf("Invalid book number!\n");
    }
}

void searchBook() {
    system("cls");
    heading();
    system("COLOR b5");
    char searchTerm[100];
    int found = 0;

    printf("\n\nEnter title or author to search: ");
    scanf(" %[^\n]s", searchTerm);

    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, searchTerm) != NULL || strstr(books[i].author, searchTerm) != NULL) {
            printf("Title: %s, Author: %s, Price: $%.3f, Quantity: %d\n",
                books[i].title, books[i].author, books[i].price, books[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found matching the search term.\n");
    }
}

float purchaseBooks() {
    system("cls");
    system("COLOR b7");
    heading();
    int bookIndex, quantity;
    float totalPrice = 0.0;
    char choice;

    listBooks();

    do {
        printf("\n\nEnter the book number to purchase (0 to exit): ");
        scanf("%d", &bookIndex);

        if (bookIndex == 0) {
            break;
        }

        bookIndex--;

        if (bookIndex >= 0 && bookIndex < bookCount) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity <= books[bookIndex].quantity) {
                float bookPrice = books[bookIndex].price;
                totalPrice += quantity * bookPrice;
                books[bookIndex].quantity -= quantity;
                strcpy(purchasedBooks[purchasedBookCount].title, books[bookIndex].title);
                strcpy(purchasedBooks[purchasedBookCount].author, books[bookIndex].author);
                purchasedBooks[purchasedBookCount].price = bookPrice;
                purchasedBooks[purchasedBookCount].quantity = quantity;
                purchasedBookCount++;
            } else {
                printf("Insufficient quantity in stock.\n");
            }
        } else {
            printf("Invalid book select!!\n");
        }

        printf("Do you want to add another book? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Total Price: $%.3f\n", totalPrice);
    return totalPrice;
}

void generateCashMemo(float totalPrice) {
    system("cls");
    heading();
    printf("\n\n=============================Cash Memo==============================\n");
    printf("---------------------------------------------------------------------\n");
    printf("Title\t\tAuthor\t\tPrice\t\tQuantity\tTotal\n");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < purchasedBookCount; i++) {
        float totalBookPrice = purchasedBooks[i].price * purchasedBooks[i].quantity;
        printf("%s\t\t%s\t\t%.3f\t\t%d\t\t%.3f\n", purchasedBooks[i].title, purchasedBooks[i].author, purchasedBooks[i].price, purchasedBooks[i].quantity, totalBookPrice);
    }

    printf("----------------------------------------------------------------------\n");
    printf("Total Price: $%.3f\n", totalPrice);
    printf("---------------------------------------------------------------------\n");
}

int main() {
    system("cls");
    int choice;
    system("COLOR f3");
    heading();

    char correctUserId[] = "sajid";
    char correctPassword[] = "@123";
    char userId[100];
    char password[100];

    int attempts = 5;

    while (attempts > 0) {
        printf("\n\n\n\t\t %c%c Enter User ID: ", ch, ch);
        scanf("%s", userId);

        printf("\n\n \n\t\t%c%c Enter Password: ", ch, ch);
        scanf("%s", password);

        if (strcmp(userId, correctUserId) == 0 && strcmp(password, correctPassword) == 0) {
            printf("\n\t\t Login successful!\n");
            break;
        } else {
            printf("\n\t\t Invalid User ID or Password. %d attempts remaining!!!\n", attempts - 1);
            attempts--;
        }
    }

    if (attempts == 0) {
        printf("Maximum login attempts reached. Account locked.\n");
        exit(1);
    }

    do {
        displayMenu();
        for (int i = 1; i <= 26; i++)
            printf("%c", ch);
        printf("\n\n %c%c Enter your choice--->>>\ ", ch, ch);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                editBook();
                break;
            case 4:
                searchBook();
                break;
            case 5: {
                float totalPrice = purchaseBooks();
                generateCashMemo(totalPrice);
                break;
            }
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! \nPlease try again.\n");
        }
    } while (choice != 6);

    return 0;
}

