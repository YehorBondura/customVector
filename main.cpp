
#include <iostream>
#include "menuOfVector.h"

class customVector
{
public:

	int getMemory() const { return memory; }
	int setMemory(int newMemory) { memory = newMemory; }

	customVector(int startmemory = 0)
	{
		memory = startmemory;
		dinamicArray = nullptr;
		if (memory > 0)
		{
			dinamicArray = new int[memory];
		}
	}
	~customVector()
	{
		delete[] dinamicArray;
	}
	customVector(const customVector& other)
		:memory(other.memory)
	{
		dinamicArray = new int[memory];
		for (int i = 0; i < memory; ++i)
		{
			dinamicArray[i] = other.dinamicArray[i];
		}
	}
	customVector& operator =(const customVector& other)
	{
		if (this == &other)
		{
			return *this;
		}
		if(dinamicArray)
		{
			delete[] dinamicArray;
		}
		dinamicArray = nullptr;
		memory = other.memory;
		dinamicArray = new int[memory];
		for (int i = 0; i < memory; ++i)
		{
			dinamicArray[i] = other.dinamicArray[i];
		}
		return *this;
	}
	int operator[](unsigned int index) const
	{
		if (dinamicArray && index < memory)
		{
			return dinamicArray[index];
		}
		else
		{
			std::cout << "Index out of bounds!" << std::endl;
			return -1;
		}
	}
	int& operator[](unsigned int index)
	{
		if (dinamicArray && index < memory)
		{
			return dinamicArray[index];
		}
		else
		{
			std::cout << "Index out of bounds!" << std::endl;
		}
	}
	bool operator==(const customVector& other) const
	{
		if (memory != other.memory)
		{
			return false;
		}
		for (int i = 0; i < memory; ++i)
		{
			if (dinamicArray[i] != other.dinamicArray[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator!=(const customVector& other) const
	{
		return !(*this == other);
	}
	void resize(int newSize)
	{
		memory = newSize;
		int* dinamicArrayTemp;
		if (newSize > 0)
		{
			dinamicArrayTemp = new int[memory];
			for (int v = 0; v < memory; ++v)
			{
				dinamicArrayTemp[v] = dinamicArray[v];
			}
		}
		else 
		{
			dinamicArrayTemp = nullptr;
		}
		delete[] dinamicArray;
		dinamicArray = nullptr;
		dinamicArray = dinamicArrayTemp;
	}

	void setElement(int index, int value)
	{
		if (index >= 0 && index < memory && dinamicArray != nullptr)
		{
			dinamicArray[index] = value;
		}
		else
		{
			std::cout << "Index out of bounds!" << std::endl;
		}
	}
	int getElement(int index) const
	{
		if (index >= 0 && index < memory && dinamicArray != nullptr)
		{
			return dinamicArray[index];
		}
		if (index < 0 || index >= memory)
		{
			throw std::out_of_range("Index out of bounds!");
		}
	}
private:
	int memory;
	int* dinamicArray = nullptr;
};


int main()
{
	int sizeOfVector = 1;
	int input;
	customVector vec(sizeOfVector);
	while (true)
	{
		printMainMenu();
		std::cin >> input;
		switch (input)
		{
			case 1:
			{
				printCreateVectorMenu();
				int data;
				std::cin >> sizeOfVector;
				vec.resize(sizeOfVector);
				std::cout << "Enter the data to the vector: " << std::endl;
				for (int i = 0; i < sizeOfVector; ++i)
				{
					std::cin >> data;
					vec.setElement(i, data);
				}
				break;
			}
			case 2:
			{
				std::cout << "Memory allocated for vector: " << vec.getMemory() << std::endl;
				std::cout << "Vector data: " << std::endl;
				for (int i = 0; i < vec.getMemory(); ++i)
				{
					std::cout << vec.getElement(i) << std::endl;
				}
				break;
			}
			case 3:
			{
				int input2;
				printChangeDataMenu();
				std::cin >> input2;
				switch (input2)
				{
					case 1:
					{
						int newSize;
						std::cout << "Enter new size of vector: ";
						std::cin >> newSize;
						vec.resize(newSize);
						break;
					}
					case 2:
					{
						int index, value;
						std::cout << "Enter index of element to change: ";
						std::cin >> index;
						std::cout << "Enter new value: ";
						std::cin >> value;
						vec.setElement(index, value);
						break;
					}
					case 3:
					{
						break;
					}
				}
				break;		
			}
			case 4:
			{
				int input	;
				std::cout << "Enter index of element to print: ";
				std::cin >> input;
				int index = input - 1;
				try
				{
					int value = vec.getElement(index);
					std::cout << "Element at index " << input << ": " << value << std::endl;
				}
				catch (const std::out_of_range& e)
				{
					std::cout << e.what() << std::endl;
				}
				break;
			}
			case 5:
			{
				return 0;
			}
		}
	}
	return 0;
}
