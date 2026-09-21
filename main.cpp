
#include <iostream>
#include "menuOfVector.h"

template <typename T>
class customVector
{
public:
	int getMemory() const { return memory; }

	customVector() : dinamicArray(nullptr), memory(0) {}
	customVector(size_t initialSize) : memory (initialSize)
	{
		if (initialSize > 0)
		{
			dinamicArray = new T[initialSize];
		}
		else
		{
			dinamicArray = nullptr;
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

	explicit operator bool() const
	{
		return memory > 0;
	}

	void resize(int newSize)
	{
		T* dinamicArrayTemp = nullptr;
		if (newSize > 0)
		{
			dinamicArrayTemp = new T[newSize];
			if (memory < newSize)
			{
				for (size_t v = 0; v < memory; ++v)
				{
					dinamicArrayTemp[v] = dinamicArray[v];
				}
			}
			if (memory > newSize)
			{
				for (size_t v = 0; v < newSize; ++v)
				{
					dinamicArrayTemp[v] = dinamicArray[v];
				}
			}
		}
		else 
		{
			dinamicArrayTemp = nullptr;
			memory = 0;
		}
		delete[] dinamicArray;
		dinamicArray = nullptr;
		dinamicArray = dinamicArrayTemp;
		memory = newSize;
	}

	void setElement(size_t index, size_t value)
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
	T getElement(size_t index) const
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
	T* dinamicArray;
};

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
	customVector<int> vec(sizeOfVector);
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
