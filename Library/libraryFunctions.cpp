#include <iostream>
#include "book.h"
#include <algorithm>
#include "person.h"
#include <sstream>

void showAllBooks(Book library[], int size) {
	for (int i = 0; i < size; i++)
		library[i].showBook();
}
//This function allows to display all the books from the library.
bool sortByTitle(Book const& t1, Book const& t2) {
	return t1.title < t2.title;
}
bool sortByAuthor(Book const& a1, Book const& a2) {
	return a1.author < a2.author;
}
bool sortByRating(Book const& r1, Book const& r2) {
	return r1.rating > r2.rating;
}
//This three function are auxiliary for function sortAllBooksBy.
//Allows to proper sorting.
void sortAllBooksBy(Book library[], int size) {
	int option;
	std::cout << "1.Title\n2.Author\n3.Rating\n4.Exit\n\n";
	std::cin >> option;
	switch (option) {
	case 1:
		std::sort(library, library + size, sortByTitle);
		break;
	case 2:
		std::sort(library, library + size, sortByAuthor);
		break;
	case 3:
		std::sort(library, library + size, sortByRating);
		break;
	case 4:
		return ;
		break;
	default:
		std::cout << "You have choosen wrong number\n";
		break;
	}
}
//This function allows user to sort whole library
void addNewBook(Book library[], int& size) {
	std::string title, author, categorie;
	float rating = 0;
	std::cout << "Type title: ";
	std::getline(std::cin, title);
	std::cout << "Type author: ";
	std::getline(std::cin, author);
	std::cout << "Type categorie: ";
	std::getline(std::cin, categorie);
	rt:
	std::cout<<"Give your rating(1-10): ";
	std::cin >> rating;
	std::cin.ignore();
	if (rating <= 10 && rating > 0) {
		for (int i = 0; i < size; i++) {
			if (title == library[i].title && author == library[i].author && library[i].amount != 0){
				++library[i].amount;
				goto skip;
			}
		}
		Book b1(title, author, categorie, rating);
		library[size++] = b1;
	}
	else {
		std::cout << "Incorrect input, the number must be between 0-10\n";
		goto rt;
	}
	skip:
	std::cout<<std::endl;
	
}
void addNewBooks(Book library[], int& size) {
	std::string title, author, categorie;
	float rating = 0;
	int numberOfBooks = 0;
	std::cout << "Type title: ";
	std::getline(std::cin, title);
	std::cout << "Type author: ";
	std::getline(std::cin, author);
	std::cout << "Type categorie: ";
	std::getline(std::cin, categorie);
rt:
	std::cout << "Set rating(1-10): ";
	std::cin >> rating;
	std::cout << "\nGive number of books: ";
	std::cin >> numberOfBooks;
	std::cin.ignore();
	if (rating <= 10 && rating > 0) {
		for (int i = 0; i < size; i++) {
			if (title == library[i].title && author == library[i].author && library[i].amount != 0) {
				library[i].amount +=numberOfBooks;
				goto skip;
			}
		}
		Book b1(title, author, categorie, rating);
		library[size++] = b1;
	}
	else {
		std::cout << "Incorrect input, the number must be between 0-10\n";
		goto rt;
	}
skip:
	std::cout << std::endl;

}
//This function allows to add new book/s to library.
//If there is a duplicated book, the function will increase the amount of 
//that book instead of adding a new item.
//Additional properties allow to set rating only between 0 and 10.
void increaseNumberOfBooks(Book library[], int &size) {
	showAllBooks(library, size);
	int option, x;
	fail:
	std::cout << "Choose position\n";
	std::cin >> option;
	if (option <= size) {
		std::cout << "Enter amount of books\n";
		std::cin >> x;
		library[option - 1].amount += x;
	}
	else {
		goto fail;
		std::cout << "You have choosen wrong position\n";
	}
}
//This function allows Administrator to increase number of the book already owned by library
bool enterEmail(Reader dataBase[], int size, std::string enter_email) {
	if (size == 0) {
		std::cout << "There is no account in database\n";
		return 0;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (enter_email == dataBase[i].email) {
				if (dataBase[i].enterPassword(dataBase[i]))
					return 1;
				else
					return 0;
			}
		}
		std::cout << "Given e-mail haven't been found in database.\nTry again or make new account.\n";
		return 0;
	}
}
bool enterEmail(Administrator dataBase[], int size, std::string enter_email) {
	if (size == 0) {
		std::cout << "There is no account in database\n";
		return 0;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (enter_email == dataBase[i].email) {
				if (dataBase[i].enterPassword(dataBase[i]))
					return 1;
				else
					return 0;
			}
		}
		std::cout << "Given e-mail haven't been found in database.\nTry again or make new account.\n";
		return 0;
	}
}
//This function is for searching email in datebase.
//If function find imputed email it will begin another function called enterPassword
int position(Reader dataBase[], int size, std::string enter_email) {
	for (int i = 0; i < size; i++) {
		if (enter_email == dataBase[i].email)
			return i;
	}
	return 0;
}
int position(Administrator dataBase[], int size, std::string enter_email) {
	for (int i = 0; i < size; i++) {
		if (enter_email == dataBase[i].email)
			return i;
	}
	return 0;
}
//This funtcion is axuiliary.
//The function is looking for position of inputed email.
void createAccount(Reader dataBase[], int& r_size) {

	std::string new_email, new_password,confirm_password;
	begin:
	std::cout << "Type your email: \n";
	std::cin >> new_email;
	for (int i = 0; i < r_size; i++) {
		if (dataBase[i].email == new_email) {
			std::cout << "This e-mail is already taken\n";
			goto begin;
		}
	}
	fail:
	std::cout << "Type your password: \n";
	std::cin >> new_password;
	std::cout << "Confirm your password:\n";
	std::cin >> confirm_password;
	if (new_password != confirm_password) {
		std::cout << "Your password do not match, try again\n";
		goto fail;
	}
	Reader r1(new_email, new_password);
	dataBase[r_size++] = r1;
}
void createAccount(Administrator dataBase[], int& r_size) {

	std::string new_email, new_password, confirm_password;
begin:
	std::cout << "Type your email: \n";
	std::cin >> new_email;
	for (int i = 0; i < r_size; i++) {
		if (dataBase[i].email == new_email) {
			std::cout << "This e-mail is already taken\n";
			goto begin;
		}
	}
fail:
	std::cout << "Type your password: \n";
	std::cin >> new_password;
	std::cout << "Confirm your password:\n";
	std::cin >> confirm_password;
	if (new_password != confirm_password) {
		std::cout << "Your password do not match, try again\n";
		goto fail;
	}
	Administrator a1(new_email, new_password);
	dataBase[r_size] = a1;
	++r_size;
}
//This function allows new user to create new Account
//If any email is already in use, the fucntion will send message that you can't use that e-mail
void returnbook(Reader& object, Book library[], int &size) {
	for (int i = 0; i < object.amountOfBorrowedBooks; i++)
		object.borrowedBooks[i].showBook();
	int position;
	std::cin >> position;
	position -= 1;
	library[size++] = object.borrowedBooks[position];
	for (position ; position < object.amountOfBorrowedBooks; position++) {
		object.borrowedBooks[position] = object.borrowedBooks[position + 1];
	}
	Book* p = &object.borrowedBooks[position];
	p = NULL;
	object.amountOfBorrowedBooks--;
	
}
//This function is created only for readers to return book their already borrowed.
void checkForDuplicates(Book library[], int& size) {
	Book temp = library[size];
	for (int i = 0; i < size; i++) {
		if (library[i].title == temp.title && library[i].author == temp.author) {
			++library[i].amount;
			Book* p = &library[size];
			p = NULL;
			--size;
		}
	}

}
//This function is auxiliary, its operations is to delete duplicates in library.


void showBooksByCategories(Book library[], int size) {
	std::string* categories = new std::string[100];
	int position = 0;
	for (int i = 0; i < size; i++) {
		if (library[i].categorie != library[i + 1].categorie) {
			categories[position] = library[i].categorie;
			std::cout << position+1 << ". " << categories[position] << std::endl;
			++position;
		}
	}
}