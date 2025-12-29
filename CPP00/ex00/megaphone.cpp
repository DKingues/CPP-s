#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	std::string str;

	if (ac <= 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (int j = 1; j < ac; j++)
	{
		str += av[j];
		if (av[j + 1])
			str += " ";
	}
	for (size_t i = 0; i < str.size(); i++)
		std::cout << (char)toupper(str[i]);
	std::cout << std::endl;
	return 0;
}
