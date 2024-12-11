#pragma once
#ifndef LIBRARY_HELPER_H
#define LIBRARY_HELPER_H

#include "BookHelper.h"

void PrintLibrary(Book library[], int size);
void SearchByAuthor(Book library[], int size, const char* author);
void SearchByTitle(Book library[], int size, const char* title);
void SortByTitle(Book library[], int size);
void SortByAuthor(Book library[], int size);
void SortByPublisher(Book library[], int size);

void EditBook(Book& book, const char* newTitle, const char* newAuthor, const char* newPublisher, const char* newGenre);
#endif
