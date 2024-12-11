using namespace std;
#include "BookHelper.h"
#include "AllBook.h"
#include <iostream>
                     
void CreateBook(Book& sourceBook)
{
	if (sourceBook.nameBook != nullptr || sourceBook.author != nullptr || sourceBook.publishingHouse != nullptr || sourceBook.genre != nullptr)
	{
		return;
	}
	sourceBook.nameBook = new char[Book::STR_Size] {};
	sourceBook.author = new char[Book::STR_Size] {};
	sourceBook.publishingHouse = new char[Book::STR_Size] {};
	sourceBook.genre = new char[Book::STR_Size] {};
}

void InitBook(Book& sourceBook)
{
	if (sourceBook.nameBook == nullptr || sourceBook.author == nullptr || sourceBook.publishingHouse == nullptr || sourceBook.genre == nullptr)
	{
		return;
	}

	const int DAT_SIZE = 6;
	const char* ArrayBookName[DAT_SIZE]{ "Bublik i ya", "OHO", "Island", "From one hare", "The mystery of the mountain house", "Evil" };
	const char* ArrayAuthorName[DAT_SIZE]{ "Florian Denison", "Andrey Petrov", "Artem Wasili", "Jamaica Shyshkov", "Ivan Sokolov ", "George Orwell" };
	const char* ArrayPublishingHouseName[DAT_SIZE]{ "New Book", "Coslov", "Sovet", "Darf", "Vavilon", "Aboba" };
	const char* ArrayGenreName[DAT_SIZE]{ "Fiction", "Mystery", "Thriller", "Science fiction", "Fantasy ", "Historical " };

	strcpy_s(sourceBook.nameBook, Book::STR_Size, ArrayBookName[rand() % DAT_SIZE]);
	strcpy_s(sourceBook.author, Book::STR_Size, ArrayAuthorName[rand() % DAT_SIZE]);
	strcpy_s(sourceBook.publishingHouse, Book::STR_Size, ArrayPublishingHouseName[rand() % DAT_SIZE]);
	strcpy_s(sourceBook.genre, Book::STR_Size, ArrayGenreName[rand() % DAT_SIZE]);
}

void PrintBook(const Book& sourceBook)
{
	if (sourceBook.nameBook == nullptr || sourceBook.author == nullptr || sourceBook.publishingHouse == nullptr || sourceBook.genre == nullptr)
	{
		return;
	}

	cout << "---------------------------------------" << endl;
	cout << "Book title: " << sourceBook.nameBook << endl;
	cout << "Author of the book: " << sourceBook.author << endl;
	cout << "Publishing house: " << sourceBook.publishingHouse << endl;
	cout << "Book genre: " << sourceBook.genre << endl;
	cout << "---------------------------------------" << endl;
}

void DeleteBook(Book& sourceBook)
{
	delete[] sourceBook.nameBook;
	sourceBook.nameBook = nullptr;

	delete[] sourceBook.author;
	sourceBook.author = nullptr;

	delete[] sourceBook.publishingHouse;
	sourceBook.publishingHouse = nullptr;

	delete[] sourceBook.genre;
	sourceBook.genre = nullptr;
}