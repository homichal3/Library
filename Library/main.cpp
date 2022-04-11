#include <iostream>
#include "book.h"
#include <algorithm>
#include "libraryFunctions.h"
#include "person.h"



int main() {
	int size=0;
	Book* library = new Book[100];
	for (int i = 0; i <5; i++) {
		addNewBook(library, size);
	}
	Reader* r_dataBase = new Reader[100];
	Administrator* a_dataBase = new Administrator[100];
	int r_size = 0, a_size = 0;
	std::string enter_email;


	while (true) {
		int option;
		std::cout << "\n\n|=========================================================|\n";
		std::cout << "|=====================Panel for Readers===================|\n";
		std::cout << "| 1. Sign in                                              |\n";
		std::cout << "| 2. Log in                                               |\n";
		std::cout << "|=========================================================|\n";
		std::cout << "|=================Panel for Administrators================|\n";
		std::cout << "|=========================================================|\n";
		std::cout << "| 3. Create account                                       |\n";
		std::cout << "| 4. Enter operation panel                                |\n";
		std::cout << "| 5. EXIT                                                 |\n";
		std::cout << "|=========================================================|\n";
		std::cin >> option;
		switch (option) {
		case 1:
			createAccount(r_dataBase, r_size);
			std::cout << "You created account!\n";
			break;
		case 2:
			std::cout << "Enter your e-mail\n";
			std::cin >> enter_email;
			if (enterEmail(r_dataBase, r_size, enter_email))
				r_dataBase[position(r_dataBase, r_size, enter_email)].openMenu(r_dataBase[position(r_dataBase, r_size, enter_email)], library, size);
			break;
		case 3:
			createAccount(a_dataBase, a_size);
			std::cout << "You created account!\n";
			break;
		case 4:
			std::cout << "Enter your e-mail\n";
			std::cin >> enter_email;
			std::cin.ignore();
			if (enterEmail(a_dataBase, a_size, enter_email))
				a_dataBase[position(a_dataBase, a_size, enter_email)].openMenu(a_dataBase[position(a_dataBase, a_size, enter_email)], library, size);
			break;
		case 5:
			return 0;
		}
	}
	std::cout << "Thank you, come again!\n";
	delete[]library;
	delete[]a_dataBase;
	delete[]r_dataBase;
	return 0;
}