using namespace std;
#include <iostream>
#include <time.h>
#include "BookHelper.h"
#include "LibraryHelper.h"


void ShowMenu() {
    cout << "\n=== LIBRARY MENU ===\n";
    cout << "1. Edit book\n";
    cout << "2. Print all books\n";
    cout << "3. Search books by author\n";
    cout << "4. Search for a book by title\n";
    cout << "5. Sort an array by book titles\n";
    cout << "6. Sort array by author\n";
    cout << "7. Sort the array by publisher\n";
    cout << "0. Exit\n";
    cout << "Select an option: ";
}


int main()
{
	srand(time(NULL));

    const int LIBRARY_SIZE = 10;
    Book library[LIBRARY_SIZE];

    // Инициализация библиотеки
    for (int i = 0; i < LIBRARY_SIZE; ++i) {
        CreateBook(library[i]);
        InitBook(library[i]);
    }

    int choice;
    do {
        ShowMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int index;
            char newTitle[Book::STR_Size], newAuthor[Book::STR_Size];
            char newPublisher[Book::STR_Size], newGenre[Book::STR_Size];

            cout << "Enter book index (1-" << LIBRARY_SIZE << "): ";
            cin >> index;
            if (index < 1 || index > LIBRARY_SIZE) {
                cout << "Invalid index!" << endl;
                break;
            }
            cin.ignore(); // Очистка ввода
            cout << "Enter a new book nema: ";
            cin.getline(newTitle, Book::STR_Size);
            cout << "Enter a new book author: ";
            cin.getline(newAuthor, Book::STR_Size);
            cout << "Enter a new book publisher: ";
            cin.getline(newPublisher, Book::STR_Size);
            cout << "Enter a new book genre: ";
            cin.getline(newGenre, Book::STR_Size);

            EditBook(library[index - 1], newTitle, newAuthor, newPublisher, newGenre);
            break;
        }
        case 2:
            cout << "List of all books:\n";
            PrintLibrary(library, LIBRARY_SIZE);
            break;
        case 3: {
            char author[Book::STR_Size];
            cin.ignore(); // Очистка ввода
            cout << "Enter the author's name: ";
            cin.getline(author, Book::STR_Size);
            SearchByAuthor(library, LIBRARY_SIZE, author);
            break;
        }
        case 4: {
            char title[Book::STR_Size];
            cin.ignore(); // Очистка ввода
            cout << "Enter book title: ";
            cin.getline(title, Book::STR_Size);
            SearchByTitle(library, LIBRARY_SIZE, title);
            break;
        }
        case 5:
            SortByTitle(library, LIBRARY_SIZE);
            cout << "Books sorted by title.\n";
            break;
        case 6:
            SortByAuthor(library, LIBRARY_SIZE);
            cout << "Books sorted by author.\n";
            break;
        case 7:
            SortByPublisher(library, LIBRARY_SIZE);
            cout << "Books sorted by publisher.\n";
            break;
        case 0:
            cout << "Exit the program.\n";
            break;
        default:
            cout << "Wrong choice! Try again.\n";
        }
    } while (choice != 0);

    // Очистка памяти
    for (int i = 0; i < LIBRARY_SIZE; ++i) {
        DeleteBook(library[i]);
    }

	

	cout << endl;
	cout << "////////////////////////////////////////" << endl;
	cout << endl;
}

