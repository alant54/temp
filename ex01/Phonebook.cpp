#include "Phonebook.hpp"

PhoneBook::PhoneBook() : _number_of_contact(0) {}

void PhoneBook::add_contact(Contact new_contact)
{
	_contacts[_number_of_contact % 8] = new_contact;
	_number_of_contact++;
}

void PhoneBook::display_contacts()
{
	for (int i = 0; i < _number_of_contact && i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		if (_contacts[i]._first_name.length() > 10)
			std::cout << _contacts[i]._first_name.substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << _contacts[i]._first_name << "|";
		if (_contacts[i]._last_name.length() > 10)
			std::cout << _contacts[i]._last_name.substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << _contacts[i]._last_name << "|";
		if (_contacts[i]._nickname.length() > 10)
			std::cout << _contacts[i]._nickname.substr(0, 9) << "." << std::endl;
		else
			std::cout << std::setw(10) << _contacts[i]._nickname << std::endl;
	}
}

void PhoneBook::display_specific_contact(int index)
{
	if (index >= 0 && index < _number_of_contact && index < 8)
	{
		std::cout << "First Name: " << _contacts[index]._first_name << std::endl;
		std::cout << "Last Name: " << _contacts[index]._last_name << std::endl;
		std::cout << "Nickname: " << _contacts[index]._nickname << std::endl;
		std::cout << "Phone Number: " << _contacts[index]._phone_number << std::endl;
		std::cout << "Darkest Secret: " << _contacts[index]._darkest_secret << std::endl;
	}
	else
		std::cout << "Invalid contact index" << std::endl;
}

int main()
{
	PhoneBook phone_book;
	std::string command;
	int index;

	index = 0;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			Contact new_contact;
			std::cout << "Enter first name: ";
			std::getline(std::cin, new_contact._first_name);
			std::cout << "Enter last name: ";
			std::getline(std::cin, new_contact._last_name);
			std::cout << "Enter nickname: ";
			std::getline(std::cin, new_contact._nickname);
			std::cout << "Enter phone number: ";
			std::getline(std::cin, new_contact._phone_number);
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, new_contact._darkest_secret);
			if (new_contact._first_name.empty() || new_contact._last_name.empty() || new_contact._nickname.empty() || new_contact._phone_number.empty() || new_contact._darkest_secret.empty())
				std::cout << "Empty fields found contact not added to phone books" << std::endl;
			else
				phone_book.add_contact(new_contact);
		}
		else if (command == "SEARCH")
		{
			phone_book.display_contacts();

			std::cout << "Enter index of contact to display: ";
			if (!(std::cin >> index))
				std::cin.clear();
			else
				phone_book.display_specific_contact(index);
			std::cin.ignore();
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}