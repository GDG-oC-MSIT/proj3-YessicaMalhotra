#include <iostream>
#include <string>
using namespace std;

// basic structure to hold book details
struct Book {
    int id;
    string title;
    string author;
};

// Function to add a book
void add(Book library[], int& count, int maxBooks) {
    if (count >= maxBooks) {
        cout << "Library is full! Cannot add more books.\n";
        return;
    }

    cout << "Enter Book ID: ";
    cin >> library[count].id;
    cin.ignore(); 
    cout << "Enter Book Title: ";
    getline(cin, library[count].title);
    cout << "Enter Book Author: ";
    getline(cin, library[count].author);

    count++;
    cout << "Book added successfully!\n";
}

// Function to search for a book using Linear Search
void search(Book library[], int count) {
    cin.ignore(); 
    string searchTitle;
    cout << "Enter the title of the book to search: ";
    getline(cin, searchTitle);

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (library[i].title == searchTitle) {
            cout << "Book Found!\n";
            cout << "ID: " << library[i].id << "\nTitle: " << library[i].title << "\nAuthor: " << library[i].author << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found.\n";
    }
}

// Function to remove a book
void remove(Book library[], int& count) {
    if (count == 0) {
        cout << "Library is empty! No books to remove.\n";
        return;
    }

    cin.ignore(); 
    string removeTitle;
    cout << "Enter the title of the book to remove: ";
    getline(cin, removeTitle);

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (library[i].title == removeTitle) {
            found = true;

            // Shift all books after the removed one to the left
            for (int j = i; j < count - 1; ++j) {
                library[j] = library[j + 1];
            }
            count--; 
            cout << "Book removed successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Book not found. Unable to remove.\n";
    }
}

// Function to sort books alphabetically using Bubble Sort
void sort(Book library[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (library[j].title > library[j + 1].title) {
                swap(library[j], library[j + 1]);
            }
        }
    }
    cout << "Books sorted alphabetically by title.\n";
}

// Function to display the count of books
void total(Book library[], int count) {
    if (count == 0) {
        cout << "No books available.\n";
        return;
    }
    cout << "List of Books:\n";
    for (int i = 0; i < count; ++i) {
        cout << "ID: " << library[i].id << "\nTitle: " << library[i].title << "\nAuthor: " << library[i].author << "\n\n";
    }
}

int main() {
    const int maxBooks = 100; 
    Book library[maxBooks];  
    int count = 0;           
    int choice;

    do {
        cout << "\n LIBRARY BOOK MANAGEMENT SYSTEM \n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Remove Book\n";
        cout << "4. Sort Books\n";
        cout << "5. Total Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add(library, count, maxBooks);
                break;
            case 2:
                search(library, count);
                break;
            case 3:
                remove(library, count);
                break;
            case 4:
                sort(library, count);
                break;
            case 5:
                total(library, count);
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
