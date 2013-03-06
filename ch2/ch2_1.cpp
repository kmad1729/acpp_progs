#include <iostream>
#include <string>

int main()
{
	//ask for person's name
	std::cout << "Please enter your first name: ";

	//read the name
	std::string name;
	std::cin >> name;

	const std::string greeting = "Hello, " + name + "!";
	std::cout << greeting;
	return 0;
}
