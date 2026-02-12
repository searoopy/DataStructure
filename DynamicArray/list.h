#pragma once

#include <iostream>
#include <cassert>

//자동으로 크기가 늘어나는 배열(list/ vector)

template<typename T>
class List
{
public:
	List()
	{
		//todo: 저장 공간 할당 해야함...

		Reallocate(capacity);



	}


	~List()
	{
		if (data)
		{
			delete[] data;
		}
	}


	//값 추가 함수
	void Add(const T& value)
	{
		if (size == capacity)
		{
			Reallocate(capacity * 2);
		}



		//항목 추가.
		data[size] = value;


		++size;
	}


	void Add(T&& value)
	{
		if (size == capacity)
		{
			Reallocate(capacity * 2);
		}

		//값을 저장할때 이동처리.
		data[size] = std::move(value);

		++size;
	}


	//인덱스 연산자 오버로딩.
	T& operator[](int index)
	{
		assert(index < 0 || index >= size);

		return data[index];
	}


	int Size() const {
		return size;
	}


	int Capacity() const { return capacity;  }

private:
	//저장 공간 할당(재할당)하는 함수
	void Reallocate(int newCapacity)
	{
		//1. 이주할 새로운 공간 할당(new)
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);



		//2. 기존항목을 새로운 공간에 복사/이동.
		/*for (int i = 0; i < size; ++i)
		{
			newBlock[i] = data[i];
		}*/

		if (data)
			memcpy(newBlock, data, sizeof(T) * capacity);


		


		//3. 기존배열 공간 해제.
		if(data)
			delete[] data;

		data = newBlock;
		capacity = newCapacity;
	}

private:

	//힙에 할당하는 배열을 관리할 포인터 변수.
	T* data = nullptr;


	//배열에 저장된 항목의 수.
	int size = 0;

	//배열 저장의 공간의 크기
	int capacity = 2;

};