#include <iostream>
#include <string>

using namespace std;

class Library {
private:
    string availableBooks[10];  
    string borrowedBooks[10];   
    int availableCount;         
    int borrowedCount;          

public:
    Library() : availableCount(0), borrowedCount(0) {}

    void addBook(string book) {
        for (int i = 0; i < availableCount; i++) {
            if (availableBooks[i] == book) {
                cout << "Book \"" << book << "\" already exists in the library.\n";
                return;
            }
        }
        if (availableCount < 10) {
            availableBooks[availableCount++] = book;
            cout << "📚 Book added: " << book << endl;
        } else {
            cout << "⚠️ Library is full! Cannot add more books.\n";
        }
    }

    void borrowBook(string book) {
        if (borrowedCount >= 10) {
            cout << "⚠️ Cannot borrow more books!\n";
            return;
        }
        for (int i = 0; i < availableCount; i++) {
            if (availableBooks[i] == book) {
                borrowedBooks[borrowedCount++] = book;
                for (int j = i; j < availableCount - 1; j++) {
                    availableBooks[j] = availableBooks[j + 1];
                }
                availableCount--;
                cout << "✅ Borrowed book: " << book << endl;
                return;
            }
        }
        cout << "❌ Book \"" << book << "\" not found in the library.\n";
    }

    void returnBook(string book) {
        if (availableCount >= 10) {
            cout << "⚠️ Library is full! Cannot return books.\n";
            return;
        }
        for (int i = 0; i < borrowedCount; i++) {
            if (borrowedBooks[i] == book) {
                availableBooks[availableCount++] = book;
                for (int j = i; j < borrowedCount - 1; j++) {
                    borrowedBooks[j] = borrowedBooks[j + 1];
                }
                borrowedCount--;
                cout << "🔄 Returned book: " << book << endl;
                return;
            }
        }
        cout << "❌ Book \"" << book << "\" was not borrowed.\n";
    }

    void displayAvailableBooks() {
        cout << "\n📖 Available Books in Library:\n";
        if (availableCount == 0) {
            cout << "⚠️ No books currently available.\n";
        } else {
            for (int i = 0; i < availableCount; i++) {
                cout << "- " << availableBooks[i] << endl;
            }
        }
    }

    void displayBorrowedBooks() {
        cout << "\n📚 Borrowed Books:\n";
        if (borrowedCount == 0) {
            cout << "✅ No books are currently borrowed.\n";
        } else {
            for (int i = 0; i < borrowedCount; i++) {
                cout << "- " << borrowedBooks[i] << endl;
            }
        }
    }
};

int main() {
    Library myLibrary;
    
    myLibrary.addBook("C++ Programming");
    myLibrary.addBook("Data Structures");
    myLibrary.addBook("Algorithms");
    
    myLibrary.displayAvailableBooks();
    
    myLibrary.borrowBook("Data Structures");
    myLibrary.displayAvailableBooks();
    myLibrary.displayBorrowedBooks();
    
    myLibrary.returnBook("Data Structures");
    myLibrary.displayAvailableBooks();
    myLibrary.displayBorrowedBooks();
    
    return 0;
}
