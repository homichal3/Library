#include <iostream>
#include "book.h"


	Book::Book() {};
	Book::Book(std::string n_title, std::string n_author, std::string n_categorie, float n_rating ){
		title = n_title;
		author = n_author;
		rating = n_rating;
		categorie = n_categorie;
		if (n_rating != 0)
			numberOfRatings += 1;
		amount += 1;
	}
	Book::Book(std::string n_title, std::string n_author, std::string n_categorie, float n_rating, int n_amount=10) {
		title = n_title;
		author = n_author;
		rating = n_rating;
		categorie = n_categorie;
		if(n_rating !=0)
			numberOfRatings += 1;
		amount = n_amount;
	}
	void Book::showBook() {
		if(amount ==1 || amount == 0)
			std::cout << "Title: " << title << "\nAuthor: " << author << "\nCategorie: " << categorie << "\nRating: " << rating <<"\nAmount of book:"<<amount << "\n\n";
		else
			std::cout << "Title: " << title << "\nAuthor: " << author << "\nCategorie: " << categorie << "\nRating: " << rating << "\nAmount of books:" << amount << "\n\n";

	}
	

	Book::~Book() {}