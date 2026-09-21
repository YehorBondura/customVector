#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class vector {
	private:
		T* data;
		size_t size;
		size_t capacity;

	public:
		size_t getMemory() const { return size; }
		vector(): data(nullptr), size(0), capacity(0) {}
		vector(size_t initialCapacity) : size(0), capacity(initialCapacity * 2) 
		{
			if (capacity > 0)
			{
				data = new T[capacity];
			}
			else
			{
				data = nullptr;
			}
		}
		~vector()
		{
			delete[] data;
		};
		vector(const vector& other) : size(other.size), capacity(other.capacity) 
		{
			if (capacity > 0)
			{
				data = new T[capacity];
				for (size_t i = 0; i < size; ++i)
				{
					data[i] = other.data[i];
				}
			}
			else
			{
				data = nullptr;
			}
		}

		friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
		friend std::istream& operator>>(std::istream& out, Vector& vector)

		vector& operator=(const vector& other)
		{
			if (this == &other)
			{
				return *this;
			}
			if (data)
			{
				delete[] data;
			}
			data = nullptr;
			size = other.size;
			capacity = other.capacity;
			if (capacity > 0)
			{
				data = new T[capacity];
				for (size_t i = 0; i < size; ++i)
				{
					data[i] = other.data[i];
				}
			}
			return *this;
		};
		const T& operator[](size_t index) const
		{
			if (data && index < size)
			{
				return data[index];
			}
			else
			{
				throw std::out_of_range("Index out of bounds!");
			}
		};
		T& operator[](size_t index)
		{
			if (data && index < size)
			{
				return data[index];
			}
			else
			{
				throw std::out_of_range("Index out of bounds!");
			}
		};
		bool operator==(const vector& other) const
		{
			if (size != other.size)
			{
				return false;
			}
			for (size_t i = 0; i < size; ++i)
			{
				if (data[i] != other.data[i])
				{
					return false;
				}
			}
			return true;
		};
		bool operator!=(const vector& other) const
		{
			return !(*this == other);
		};
		explicit operator bool() const
		{
			return size > 0;
		};
		void resize(size_t newSize)
		{
			if (newSize == 0)
			{
				delete[] data;
				data = nullptr;
				size = 0;
				capacity = 0;
				return;
			}

			if (newSize <= capacity)
			{
				size = newSize;
				return;
			}

			size_t newCapacity = (capacity == 0) ? 1 : capacity;
			while (newCapacity < newSize)
				newCapacity *= 2;

			T* newData = new T[newCapacity];
			for (size_t i = 0; i < size; ++i)
			{
				newData[i] = data[i];
			}

			delete[] data;
			data = newData;
			size = newSize;
			capacity = newCapacity;
		}
		void setElement(size_t index, const T& value)
		{
			if (index < capacity)
			{
				data[index] = value;
			}
			else
			{
				throw std::out_of_range("Index out of bounds");
			}
		};
		T getElement(size_t index) const
		{
			if (index < capacity && data != nullptr)
			{
				return data[index];
			}
			else
			{
				throw std::out_of_range("Index out of bounds");
			}
		};
		void push_back(const T& value)
		{
			if (size == capacity)
			{
				size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
				T* newData = new T[newCapacity];
				for (size_t i = 0; i < size; ++i)
					newData[i] = data[i];
				delete[] data;
				data = newData;
				capacity = newCapacity;
			}

			data[size] = value;
			++size;
		}
};