#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
public:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

class PhoneBook
{
private:
	Contact _contacts[8];
	int _number_of_contact;

public:
	PhoneBook();
	void	add_contact(Contact new_contact);
	void	display_contacts();
	void	display_specific_contact(int index);
};

#endif