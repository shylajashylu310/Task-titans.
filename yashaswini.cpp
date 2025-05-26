#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool issued;

public:
    Book(string t, string a, string i)
        : title(t), author(a), isbn(i), issued(false) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    bool isIssued() const { return issued; }

    void issueBook() {
        if (!issued) {
            issued = true;
            cout << "Book issued: " << title << endl;
        } else {
            cout << "Book already issued.\n";
        }
    }

    void returnBook() {
        if (issued) {
            issued = false;
            cout << "Book returned: " << title << endl;
        } else {
            cout << "Book was not issued.\n";
        }
    }

    void display() const {
        cout << "Title: " << title
             << ", Author: " << author
             << ", ISBN: " << isbn
             << ", Status: " << (issued ? "Issued" : "Available") << endl;
    }
};

class Member {
private:
    string name;
    int id;
    vector<string> borrowedBooks;

public:
    Member(string n, int i) : name(n), id(i) {}

    string getName() const { return name; }
    int getId() const { return id; }

    void borrowBook(string isbn) {
        borrowedBooks.push_back(isbn);
    }

    void returnBook(string isbn) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if (*it == isbn) {
                borrowedBooks.erase(it);
                break;
            }
        }
    }
};

