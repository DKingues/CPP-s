#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret(""){};

void	Contact::setInfo()
{
	std::string temp;

	std::cout << "First Name: ";
	if (std::cin.eof())
		exit(0);
	std::cin >> firstName;
	std::cout << "\033[1A\r\033[2K" << "\033[1;32mFirst Name: \033[0m" << firstName << std::flush << std::endl;
	std::cout << "Last Name: ";
	if (std::cin.eof())
		exit(0);
	std::cin >> lastName;
	std::cout << "\033[1A\r\033[2K" << "\033[1;32mLast Name: \033[0m" << lastName << std::flush << std::endl;
	std::cout << "Nickname: ";
	if (std::cin.eof())
		exit(0);
	std::cin >> nickname;
	std::cout << "\033[1A\r\033[2K" << "\033[1;32mNickname: \033[0m" << nickname << std::flush << std::endl;
	std::cout << "Phone Number: ";
	phoneNumber = validPhoneNumber();
	std::cout << "\033[1A\r\033[2K" << "\033[1;32mPhone Number: \033[0m" << phoneNumber << std::flush << std::endl;
	std::cin.ignore(1, '\n');
	std::cout << "Darkest Secret: ";
	if (std::cin.eof())
		exit(0);
	std::getline(std::cin, darkestSecret);
	std::cout << "\033[1A\r\033[2K" << "\033[1;32mDarkest Secret: \033[0m" << darkestSecret << std::flush << std::endl;
	std::cout << std::endl << "\033[1;32mContact added.\033[0m" << std::endl << std::endl;
}

std::string	Contact::validPhoneNumber(void)
{
	std::string input;
	bool	isValid;
	while (1)
	{
		if (std::cin.eof())
			exit(0);
		std::cin >> input;
		isValid = true;
		for (size_t i = 0; input[i]; i++)
		{
			if (!isdigit(input[i]))
			{
				isValid = false;
				break;
			}
		}
		if (isValid)
			return (input);
		std::cout << "\033[1A\r\033[2K" << "\033[1;31mPhone Number: \033[0m" << std::flush;
	} 
}

void	Contact::getInfo()
{
	std::cout << "First Name:     " << firstName << std::endl;
	std::cout << "Last Name:      " << lastName << std::endl;
	std::cout << "Nickname:       " << nickname << std::endl;
	std::cout << "Phone Number:   " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
	std::cout << std::endl;
}

std::string Contact::get_fN()
{
	std::string temp;

	temp = firstName;
	if (firstName.size() > 10)
	{
		temp = firstName.substr(0, 9);
		temp += '.';
	}
	return (temp);
}

std::string Contact::get_lN()
{
	std::string temp;

	temp = lastName;
	if (lastName.size() > 10)
	{
		temp = lastName.substr(0, 9);
		temp += '.';
	}
	return (temp);
}

std::string Contact::get_nN()
{
	std::string temp;

	temp = nickname;
	if (nickname.size() > 10)
	{
		temp = nickname.substr(0, 9);
		temp += '.';
	}
	return (temp);
}
