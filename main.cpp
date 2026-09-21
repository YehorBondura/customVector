
#include <iostream>
#include "menuOfVector.h"
#include "vector.h"


template<typename T, std::size_t N>
class StaticArray
{
	public:
		StaticArray() : data_{} {}
		T& operator[](std::size_t index)
		{
			if (index < N)
			{
				return data_[index];
			}
			else
			{
				throw std::out_of_range("Index out of bounds");
			}
		}
		const T& operator[](std::size_t index) const
		{
			if (index < N)
			{
				return data_[index];
			}
			else
			{
				throw std::out_of_range("Index out of bounds");
			}
		}

		void setElement(std::size_t index, const T& value)
		{
			if (index < N)
			{
				data_[index] = value;
			}
			else
			{
				std::cout << "Index out of bounds" << std::endl;
			}
		}

		T getElement(std::size_t index) const
		{
			if (index < N)
			{
				return data_[index];
			}
			else
			{
				throw std::out_of_range("Index out of bounds");
			}
		}
	private:
		T data_[N]{};
};




int main()
{
	int sizeOfVector = 0;
	int input;
	vector<int> vec(sizeOfVector);
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
				try
				{
					for (int i = 0; i < vec.getMemory(); ++i)
					{
						std::cout << vec.getElement(i) << std::endl;
					}
				}
				catch (const std::exception&)
				{
					std::cout << "Error occurred while accessing vector elements!" << std::endl;
				}	
				break;
			}
			case 3:
			{
				std::cout << "Enter the value to add to the vector: ";
				int value;
				std::cin >> value;
				vec.push_back(value);
				break;
			}
			case 4:
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
			case 5:
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
			case 6:
			{
				return 0;
			}
		}
	}
	return 0;
}
