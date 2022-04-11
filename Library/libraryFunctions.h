#pragma once
#include <iostream>
#include "book.h"
#include <algorithm>
#include "person.h"


void showAllBooks(Book library[], int size);
bool sortByTitle(Book const& b1, Book const& b2);
bool sortByAuthor(Book const& b1, Book const& b2);
void addNewBook(Book library[], int& size);
void addNewBooks(Book library[], int& size);
bool sortByRating(Book const& r1, Book const& r2);
void sortAllBooksBy(Book library[], int size);
void showBooksByCategories(Book libaray[], int size);
void increaseNumberOfBooks(Book library[], int& size);