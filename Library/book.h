#pragma once
#include <iostream>

class Book {
private:
	std::string title;
	std::string author;
	std::string categorie;
	float rating=0;
	int numberOfRatings=0;
public:
	int amount = 0;
	Book();
	Book(std::string n_title, std::string n_author, std::string n_categorie, float n_rating = 0);
	Book(std::string n_title, std::string n_author, std::string n_categorie, float n_rating, int n_amount);
	void showBook();
	friend bool sortByTitle(Book const& t1, Book const& t2);
	friend bool sortByAuthor(Book const& a1, Book const& a2);
	friend bool sortByRating(Book const& r1, Book const& r2);
	friend void showBooksByCategories(Book libaray[], int size);
	friend void increaseNumberOfBooks(Book library[], int& size);
	friend void addNewBook(Book library[], int& size);
	friend void addNewBooks(Book library[], int& size);
	friend void checkForDuplicates(Book library[], int& size);
	~Book();

};