#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
	public:
		PhoneBook();
		void	getIndex();
		std::string	validIndex();
		void	add();
		void	search();
		void	printInfo(int i);

	private:
		Contact contacts[8];
		int index;
		int	numberOfContacts;
};

