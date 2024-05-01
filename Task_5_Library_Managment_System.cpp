#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    Book(const string& t, const string& a, const string& i) : title(t), author(a), isbn(i), available(true) {}

    const string& getTitle() const { return title; }
    const string& getAuthor() const { return author; }
    const string& getISBN() const { return isbn; }
    bool isAvailable() const { return available; }
    void setAvailable(bool status) { available = status; }
};

class Library {
private:
    vector<Book> books;
    string filename;

public:
    Library(const string& file) : filename(file) {
        // Load book data from file into memory
        loadBooks();
    }

    void loadBooks() {
        ifstream infile(filename);
        string title, author, isbn;
        while (infile >> title >> author >> isbn) {
            books.emplace_back(title, author, isbn);
        }
        infile.close();
    }

    void saveBooks() {
        ofstream outfile(filename);
        for (const auto& book : books) {
            outfile << book.getTitle() << " " << book.getAuthor() << " " << book.getISBN() << " " << book.isAvailable() << endl;
        }
        outfile.close();
    }

    void searchByTitle(const string& title) {
        bool found = false;
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    // Similar functions for author and ISBN search

    void checkoutBook(const string& isbn) {
        for (auto& book : books) {
            if (book.getISBN() == isbn && book.isAvailable()) {
                book.setAvailable(false);
                cout << "Book checked out successfully." << endl;
                return;
            }
        }
        cout << "Book not available or not found." << endl;
    }

    void returnBook(const string& isbn) {
        for (auto& book : books) {
            if (book.getISBN() == isbn && !book.isAvailable()) {
                book.setAvailable(true);
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not checked out or not found." << endl;
    }

    void displayMenu() {
        cout << "========== Book Library Management System ==========" << endl;
        cout << "1. Search Book by Title" << endl;
        cout << "2. Search Book by Author" << endl;
        cout << "3. Search Book by ISBN" << endl;
        cout << "4. Check Out a Book" << endl;
        cout << "5. Return a Book" << endl;
        cout << "6. Exit" << endl;
        cout << "=====================================================" << endl;
    }

    void processChoice(int choice) {
        switch (choice) {
            case 1: {
                string title;
                cout << "Enter title to search: ";
                cin.ignore();
                getline(cin, title);
                searchByTitle(title);
                break;
            }
            // Implement similar cases for author, ISBN search, checkout, and return
            case 6:
                saveBooks(); // Save data before exiting
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
};

int main() {
    Library library("books.txt");
    int choice;

    do {
        library.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        library.processChoice(choice);
    } while (choice != 6);

    return 0;
}
