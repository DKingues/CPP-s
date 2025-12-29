#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	public:
		Contact();
		void	setInfo();
		void	getInfo();
		std::string validPhoneNumber();
		std::string get_fN();
		std::string get_lN();
		std::string get_nN();

	private:
		std::string firstName;
		std::string lastName;
		std::string	nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

