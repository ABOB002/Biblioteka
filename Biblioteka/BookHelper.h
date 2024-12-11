#pragma once
#ifndef BOOK_HELPER_H
#define BOOK_HELPER_H

struct Book
{

	static const int STR_Size = 256;
	char* nameBook = nullptr;
	char* author = nullptr;
	char* publishingHouse = nullptr;
	char* genre = nullptr;
};


void CreateBook(Book& sourceBook);
void InitBook(Book& sourceBook);
void PrintBook(const Book& sourceBook);
void DeleteBook(Book& sourceBook);




#endif // !BOOK_HELPER_H


