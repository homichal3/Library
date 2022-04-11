#include <iostream>
#include "person.h"
#include <conio.h>
#include "libraryFunctions.h"


Person::Person() {};
Person::~Person() {};


Reader::Reader() {};
Reader::Reader(std::string n_email, std::string n_password) {
	email = n_email;
	password = n_password;
	amount++;
}
bool Reader::enterPassword(Reader & object) {
	std::string enter_password;
	std::cout << "Enter your password: \n";
	char ch;
	ch = _getch();
	while (ch != 13) {
		enter_password.push_back(ch);
		std::cout << "*";
		ch = _getch();
	}
	if (enter_password == object.password) {
		std::cout << "\nYour password is correct\n";
		return 1;
	}
	else
		std::cout << "\nYour password is wrong\n";
	return 0;
}
//This function is strictly connected with funciton enterEmail.
//If enterEmail passed, this function will check inputed password.
void Reader::changeEmail() {
	std::string new_email;
	std::cout << "Type new e-mail\n";
	std::cin >> new_email;
	email = new_email;
	std::cout << "Your, e-mail has been sucesfully changed\n";
}
//This function allowed reader to change his e-mail.
void Reader::changePassword() {
	std::string new_password;
	std::cout << "Enter your old Password:\n";
	char ch;
	ch = _getch();
	while (ch != 13) {
		new_password.push_back(ch);
		std::cout << "*";
		ch = _getch();
	}
	if (new_password == password) {
		std::cout << "\nType new password\n";
		std::cin >> new_password;
		password = new_password;
	}
	else 
		std::cout << "Incorrect password\n";
}
//This function allowed reader to change his password.
void Reader::showAccount() {
	std::cout << "Your e-mail: " << email;
	std::cout << "\nYour password: ";
	for (int i = 0; i < password.size(); i++) {
		std::cout << "*";
	}
	std::cout << "\nBooks you have borrowed: \n";
	for (int i = 0; i < amountOfBorrowedBooks; i++)
		borrowedBooks[i].showBook();
}
//This function show reader his e-mail, password which is hidden and book that reader already borrowed.
void Reader::borrowBook(Reader& object, Book library[], int size) {
	sortAllBooksBy(library, size);
	showAllBooks(library, size);
	std::cout << "Choose the book which you will like to borrow\n";
	int x;
	std::cin >> x;
	if (library[x - 1].amount > 0) {
		object.borrowedBooks[object.amountOfBorrowedBooks] = library[x - 1];
		object.borrowedBooks[object.amountOfBorrowedBooks].amount -= library[x - 1].amount - 1;
		object.amountOfBorrowedBooks++;
		library[x - 1].amount--;
	}
	else
		std::cout << "This book is out of order\n";
}
//This function allows reader to borrow book from library.
int Reader::openMenu(Reader & object,Book library[], int size) {
	while(true){
	int option;
	std::cout << "\n\n|=========================================================|\n";
	std::cout << "|=========================MENU============================|\n";
	std::cout << "|=========================================================|\n";
	std::cout << "| 1. Borrow book                                          |\n";
	std::cout << "| 2. Check your account (book/books you already borrowed) |\n";
	std::cout << "| 3. Show all books                                       |\n";
	std::cout << "| 4. Return borrowed book/books                           |\n";
	std::cout << "| 5. Change your account addres e-mail                    |\n";
	std::cout << "| 6. Change your account password                         |\n";
	std::cout << "| 7. Log out                                              |\n";
	std::cout << "|=========================================================|\n";
	std::cout << "|=========================================================|\n";
	std::cout << "|=========================================================|\n";
	std::cin >> option;
	switch (option) {
	case 1:
		borrowBook(object, library, size);
		break;
	case 2:
		object.showAccount();
		break;
	case 3:
		showAllBooks(library, size);
		break;
	case 4:
		returnbook(object, library, size);
		checkForDuplicates(library, size);
		break;
	case 5:
		object.changeEmail();
		break;
	case 6:
		object.changePassword();
		break;
	case 7:
		return 0;
		break;
	default:
		std::cout << "You have choosen wrong option\n";
		break;
	}
	}
};
//This function is shows menu for reader.
Reader::~Reader(){}


Administrator::Administrator() {};
Administrator::Administrator(std::string n_email, std::string n_password) {
	email = n_email;
	password = n_password;
	amount++;
};
bool Administrator::enterPassword(Administrator const& object) {
	std::string enter_password;
	std::cout << "Enter your password: \n";
	char ch;
	ch = _getch();
	while (ch != 13) {
		enter_password.push_back(ch);
		std::cout << "*";
		ch = _getch();
	}
	if (enter_password == object.password) {
		std::cout << "\nYour password is correct\n";
		return 1;
	}
	else
		std::cout << "\nYour password is wrong\n";
	return 0;
}
//This function is strictly connected with funciton enterEmail.
//If enterEmail passed, this function will check inputed password.
void Administrator::changeEmail() {
	std::string new_email;
	std::cout << "Type new e-mail\n";
	std::cin >> new_email;
	email = new_email;
	std::cout << "Your, e-mail has been sucesfully changed\n";
}
//This function allowed reader to change his e-mail.
void Administrator::changePassword() {
	std::string new_password;
	std::cout << "Enter your old Password:\n";
	char ch;
	ch = _getch();
	while (ch != 13) {
		new_password.push_back(ch);
		std::cout << "*";
		ch = _getch();
	}
	if (new_password == password) {
		std::cout << "Type new password\n";
		std::cin >> new_password;
		password = new_password;
	}
	else
		std::cout << "Incorrect password\n";
}
//This function allowed reader to change his password.
//This function is shows menu for administrator.
int Administrator::openMenu(Administrator & object, Book library[], int size) {
	while (true) {
		int option;
		std::cout << "\n\n|=========================================================|\n";
		std::cout << "|=========================MENU============================|\n";
		std::cout << "|=========================================================|\n";
		std::cout << "| 1. Deposit a new book                                   |\n";
		std::cout << "| 2. Increase number of book library already own          |\n";
		std::cout << "| 3. Show all books                                       |\n";
		std::cout << "| 4. Change your account addres e-mail                    |\n";
		std::cout << "| 5. Change your account password                         |\n";
		std::cout << "| 6. Log out                                              |\n";
		std::cout << "|=========================================================|\n";
		std::cout << "|=========================================================|\n";
		std::cout << "|=========================================================|\n";
		std::cin >> option;
		std::cin.ignore();
		switch (option) {
		case 1:
			addNewBooks(library, size);
			break;
		case 2:
			increaseNumberOfBooks(library, size);
			break;
		case 3:
			showAllBooks(library, size);
			break;
		case 4:
			object.changeEmail();
			break;
		case 5:
			object.changePassword();
			break;
		case 6:
			return 0;
			break;
		default:
			std::cout << "You have choosen wrong option\n";
			break;
		}
	}
};
Administrator::~Administrator() {};