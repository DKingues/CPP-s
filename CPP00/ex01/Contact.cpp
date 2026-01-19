#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret(""){};
Contact::~Contact(){}

void	Contact::setInfo()
{
	std::cout << "First Name: ";
	std::cin.ignore(1, '\n');
	validStringInput("First Name", firstName);
	std::cout << "Last Name: ";
	validStringInput("Last Name", lastName);
	std::cout << "Nickname: ";
	validStringInput("Nickname", nickname);
	std::cout << "Phone Number: ";
	validStringInput("Phone Number", phoneNumber);
	std::cout << "Darkest Secret: ";
	validStringInput("Darkest Secret", darkestSecret);
	std::cout << std::endl << "\033[1;32mContact added.\033[0m" << std::endl << std::endl;
}

void Contact::validStringInput(std::string name, std::string &var)
{
	std::string	input;

	if (name == "Phone Number")
		phoneNumber = validPhoneNumber();
	else
	{
		while (1)
		{
			if (std::cin.eof())
				exit(0);
			std::getline(std::cin, input);
			if (input.empty())
			{
				std::cout << "\033[1A\r\033[2K" << "\033[1;31m" << name << ": \033[0m" << std::flush;
				continue;
			}
			else
			{
				var = input;
				break;
			}
		}
	}
	std::cout << "\033[1A\r\033[2K" << "\033[1;32m" << name << ": \033[0m" << var << std::flush << std::endl;
}

std::string	Contact::validPhoneNumber(void)
{
	std::string input;
	bool		isValid;

	while (1)
	{
		if (std::cin.eof())
			exit(0);
		std::getline(std::cin, input);
		isValid = true;
		for (size_t i = 0; input[i]; i++)
		{
			if (!isdigit(input[i]) && !isspace(input[i]))
			{
				isValid = false;
				break;
			}
		}
		if (isValid && !input.empty())
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
