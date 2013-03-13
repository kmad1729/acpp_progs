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
	std::string::size_type c = 0;
	const std::string::size_type cols = 2 * pad + greeting.size() + 2;
	//separate the output from the input
	std::cout << std::endl;
	int r = 0;
	//loop invariant: after each iteration r rows are written
	while(r != rows){
		c = 0;
		while(c != cols){
			if(r == 0 || r == rows -1 || c == 0 || c == cols - 1){
				std::cout << "*";
					++c;
			}else{
				if(r == pad + 1 && c == pad + 1){
					std::cout << greeting;
					c += greeting.size();
				}else{
					std::cout << " ";
					++c;
				}
			}

		}
		std::cout << std::endl;
		++r;
	}

	return 0;
}
