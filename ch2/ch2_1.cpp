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
	const int pad = 1;
	const int rows = pad * 2 + 3;
	std::cout << std::endl;
	
	//separate the output from the input
	int r = 0;

	//invariant: we have writter r rows so far
	while(r != rows){
		std::cout << std::endl;
		++r;
	}

	std::cout << greeting;
	return 0;
}
