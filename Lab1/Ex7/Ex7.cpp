#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Book {
    int bookID;
    string isbn;
    string title;
    int publishedYear;
    vector<string> authorNames;
    double price;
};

void displayBookByISBN(Book books[], int size, string isbn) {
    for (int i = 0; i < size; i++) {
        if (books[i].isbn == isbn) {
            cout << "Book found:" << endl;
            cout << "Book ID: " << books[i].bookID << endl;
            cout << "ISBN: " << books[i].isbn << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Published Year: " << books[i].publishedYear << endl;
            cout << "Authors: ";
            for (size_t j = 0; j < books[i].authorNames.size(); j++) {
                cout << books[i].authorNames[j];
                if (j + 1 < books[i].authorNames.size()) {
                    cout << ", ";
                }
            }
            cout << endl;
            cout << fixed << setprecision(2);
            cout << "Price ($): " << books[i].price << endl;
            return;
        }
    }

    cout << "No book with ISBN " << isbn << " was found." << endl;
}

void displayAllBooks(Book books[], int size) {
    cout << "\nAll books:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "------------------------------" << endl;
        cout << "Book ID: " << books[i].bookID << endl;
        cout << "ISBN: " << books[i].isbn << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Published Year: " << books[i].publishedYear << endl;
        cout << "Authors: ";
        for (size_t j = 0; j < books[i].authorNames.size(); j++) {
            cout << books[i].authorNames[j];
            if (j + 1 < books[i].authorNames.size()) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << fixed << setprecision(2);
        cout << "Price ($): " << books[i].price << endl;
    }
    cout << "------------------------------" << endl;
}

int main() {
    Book books[5] = {
        {1, "1234", "The C Programming Language", 1988, {"Brian W. Kernighan", "Dennis M. Ritchie"}, 45.50},
        {2, "7654", "Effective C++", 2005, {"Scott Meyers"}, 39.99},
        {3, "3545", "Design Patterns", 1994, {"Erich Gamma", "Richard Helm", "Ralph Johnson", "John Vlissides"}, 55.75},
        {4, "9999", "Clean Code", 2008, {"Robert C. Martin"}, 42.00},
        {5, "8888", "Fluent Python", 2015, {"Luciano Ramalho"}, 49.90}
    };

    displayAllBooks(books, 5);

    string searchISBN;
    cout << "\nEnter ISBN to search: ";
    cin >> searchISBN;

    displayBookByISBN(books, 5, searchISBN);

    return 0;
}
