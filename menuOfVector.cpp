
#include <iostream>
#include "menuOfVector.h"

void printMainMenu()
{
    std::cout << "\nChoose operation" << std::endl;
    std::cout << "1. Create vector" << std::endl;
    std::cout << "2. Show vector" << std::endl;
	std::cout << "3. Change data of vector" << std::endl;
	std::cout << "4. Print N element of Vector" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void printCreateVectorMenu()
{
	std::cout << "\nCreating vector:" << std::endl;
	std::cout << "Enter the size of the vector: ";
	std::cout << std::endl;
}


void printChangeDataMenu()
{
	std::cout << "\nChanging vector data:" << std::endl;
	std::cout << "1. Resize vector" << std::endl;
	std::cout << "2. Change element at index" << std::endl;
	std::cout << "3. Back to main menu" << std::endl;
}