#pragma once
#include <iostream>
#include "book.h"
#include "libraryFunctions.h"

class Person {
protected:
	std::string email;
	std::string password;
public:
	int amount = 0;
	Person();
	~Person();
};


class Reader : public::Person {
public:
	Book borrowedBooks[10];
	int amountOfBorrowedBooks = 0;
	Reader();
	Reader(std::string n_email, std::string n_password);
	bool enterPassword(Reader & object);
	void changeEmail();
	void changePassword();
	void showAccount();
	int openMenu(Reader & object, Book library[], int size);
	friend bool enterEmail(Reader dataBase[], int size, std::string enter_email);
	friend int position(Reader dataBase[], int size, std::string enter_email);
	void borrowBook(Reader& object, Book library[], int size);
	friend void createAccount(Reader dataBase[], int& r_size);
	friend void returnbook(Reader& object, Book library[], int& size);
	~Reader();
};

class Administrator : public::Person {
public:
	Administrator();
	Administrator(std::string n_email, std::string n_password);
	bool enterPassword(Administrator const& object);
	void changeEmail();
	void changePassword();
	int openMenu(Administrator & object, Book library[], int size);
	friend bool enterEmail(Administrator dataBase[], int size, std::string enter_email);
	friend int position(Administrator dataBase[], int size, std::string enter_email);
	friend void createAccount(Administrator dataBase[], int& r_size);
	~Administrator();
}; 