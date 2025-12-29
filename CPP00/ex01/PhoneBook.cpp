#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : index(0), numberOfContacts(0){}

int main (int ac, char **av)
{
	PhoneBook list;
	std::string command;

	if (ac > 1 || !av[0])
		return (std::cout << "No parameters needed." << std::endl, 0);
	while (1)
	{
		std::cin >> command;
		if (command == "ADD")
			list.add();
		if (command == "SEARCH")
			list.search();
		if (command == "EXIT")
			break;
	}
	return (0);
}

std::string	PhoneBook::validIndex(void)
{
	std::string input;

	while (1)
	{
		if (std::cin.eof())
			exit(0);
		std::cin >> input;
		for (size_t i = 0; input[i]; i++)
		{
			if (!isdigit(input[i]))
			{
				std::cout <<  "\033[1A\r\033[2K" << "\033[1;31mPhonebook Index: \033[0m" << std::flush;
				break;
			}
			else if (std::atoi(input.c_str()) >= numberOfContacts)
			{
				std::cout <<  "\033[1A\r\033[2K" << "\033[1;31mPhonebook Index: \033[0m" << std::flush;
				break;
			}
			else
				return (input);
		}
	} 
}

void	PhoneBook::getIndex(void)
{
	if (numberOfContacts <= 7)
		numberOfContacts++;
	if (index >= 7)
		index = 0;
	else
		index++;
}

void	PhoneBook::add(void)
{
	std::cout << std::endl;
	contacts[index].setInfo();
	getIndex();
}

void	PhoneBook::search(void)
{
	std::string	input;

	std::cout << std::endl;
	std::cout << std::setfill('-') << "+" << std::setw(11);
	std::cout << "+" << std::setw(11) << "+" << std::setw(11);
	std::cout << "+" << std::setw(11) << "+" << std::endl;
	std::cout << "|" << std::setw(10) << std::setfill(' ') << "Index";
	std::cout << "|" << "First Name"<< "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < numberOfContacts; i++)
	{
		std::cout << std::setfill('-') << "+" << std::setw(11);
		std::cout << "+" << std::setw(11) << "+" << std::setw(11);
		std::cout << "+" << std::setw(11) << "+" << std::endl;
		std::cout << "|" << std::setw(10) << std::setfill(' ') << i;
		std::cout << "|" << std::setw(10) << contacts[i].get_fN();
		std::cout << "|" << std::setw(10) << contacts[i].get_lN();
		std::cout << "|" << std::setw(10) << contacts[i].get_nN() << "|" << std::endl;
	}
	std::cout << std::setfill('-') << "+" << std::setw(11);
	std::cout << "+" << std::setw(11) << "+" << std::setw(11);
	std::cout << "+" << std::setw(11) << "+" << std::endl << std::endl;
	input = validIndex();
	std::cout <<  "\033[1A\r\033[2K" << "\033[1;32mPhonebook Index: \033[0m" << input << std::flush << std::endl;
	std::cout << std::endl << "\033[0;36mContact Info\033[0m" << std::endl << std::endl;
	printInfo(std::atoi(input.c_str()));
}


void	PhoneBook::printInfo(int i)
{
	contacts[i].getInfo();
}