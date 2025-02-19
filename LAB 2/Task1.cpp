// Dynamic Array Structures
#include<iostream>
#include<string>
using namespace std;

struct LibraryBook {
    string bookTitle;
    string bookAuthor;
    int publicationYear;
};

int main () {
    LibraryBook singleBook;
    int bookCount;

    cout << "Enter the number of books: ";
    cin >> bookCount;
    LibraryBook *bookCollection = new LibraryBook[bookCount];

    for (int i = 0; i < bookCount; i++) {
        cout << "Enter the book title: ";
        cin >> bookCollection[i].bookTitle;
        cout << "Enter the book author: ";
        cin >> bookCollection[i].bookAuthor;
        cout << "Enter the publication year: ";
        cin >> bookCollection[i].publicationYear;
        cout << endl;
    }
    int startYear;
    cout << "Enter the start year range: ";
    cin >> startYear;

    for (int i = 0; i < bookCount; i++) {
        if(bookCollection[i].publicationYear > startYear) {
            cout << "Title: " << bookCollection[i].bookTitle << endl;
            cout << "Author: " << bookCollection[i].bookAuthor << endl;
            cout << "Year: " << bookCollection[i].publicationYear << endl;
        }
    }
    delete[] bookCollection;
}
