#include "LibraryHelper.h"
#include <iostream>
#include <cstring>
using namespace std;

void PrintLibrary(Book library[], int size) {
    for (int i = 0; i < size; ++i) {
        PrintBook(library[i]);
    }
}

void SearchByAuthor(Book library[], int size, const char* author) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(library[i].author, author) == 0) {
            PrintBook(library[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Books by author " << author << " not found.\n";
    }
}

void SearchByTitle(Book library[], int size, const char* title) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(library[i].nameBook, title) == 0) {
            PrintBook(library[i]);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book with title " << title << " not found.\n";
    }
}

void SortByTitle(Book library[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(library[j].nameBook, library[j + 1].nameBook) > 0) {
                swap(library[j], library[j + 1]);
            }
        }
    }
}

void SortByAuthor(Book library[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(library[j].author, library[j + 1].author) > 0) {
                swap(library[j], library[j + 1]);
            }
        }
    }
}

void SortByPublisher(Book library[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(library[j].publishingHouse, library[j + 1].publishingHouse) > 0) {
                swap(library[j], library[j + 1]);
            }
        }
    }
}

void EditBook(Book& book, const char* newTitle, const char* newAuthor, const char* newPublisher, const char* newGenre) {
    if (book.nameBook != nullptr) {
        strcpy_s(book.nameBook, Book::STR_Size, newTitle);
    }

    if (book.author != nullptr) {
        strcpy_s(book.author, Book::STR_Size, newAuthor);
    }

    if (book.publishingHouse != nullptr) {
        strcpy_s(book.publishingHouse, Book::STR_Size, newPublisher);
    }

    if (book.genre != nullptr) {
        strcpy_s(book.genre, Book::STR_Size, newGenre);
    }

    cout << "The book has been successfully edited.\n";
}
