#pragma once

#include <iostream>
#include <cassert>


//반복자
template<typename List>
class ListIterator
{
public:
	//타입 알리아싱 지정
	//List가 템플릿 파라미터로 넘어오는 경우 typename까지 지정.
	using ValueType = typename List::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

	ListIterator(PointerType ptr)
		:ptr(ptr)
	{
	}





	//연산자 오버로딩
	//전위 증가 연산자
	ListIterator& operator++()
	{
		++ptr;
		return *this;
	}


	//연산자 오버로딩
	//후위 증가 연산자
	ListIterator& operator++(int)
	{
		//현재 반복자를 임시저장.
		ListIterator iterator = *this;

		//내부 포인터 ++처리.
		++(*this);

		//앞서 저장했던 반복자 반환.
		return iterator;
	}


	//연산자 오버로딩
	//전위 감소 연산자
	ListIterator& operator--()
	{
		--ptr;
		return *this;
	}


	//연산자 오버로딩
	//후위 감소 연산자
	ListIterator& operator--(int)
	{
		//현재 반복자를 임시저장.
		ListIterator iterator = *this;

		//내부 포인터 --처리.
		--(*this);

		//앞서 저장했던 반복자 반환.
		return iterator;
	}


	ReferenceType operator[](int index)
	{
		return *(ptr + index);
	}

	PointerType operator->()
	{
		return ptr;
	}

	ReferenceType operator*()
	{
		return *ptr;
	}

	//비교 연산자 오버로딩
	bool operator==(const ListIterator& other) const
	{
		return ptr == other.ptr;
	}

	//비교 연산자 오버로딩
	bool operator!=(const ListIterator& other) const
	{
		return !(*this == other.ptr);
	}


private:
	//반복자는 결국 포인터.
	PointerType ptr = nullptr;
};

//자동으로 크기가 늘어나는 배열(list/ vector)

template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = ListIterator< List<T> >;


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
		//assert(index < 0 || index >= size);
		assert(index >= 0 || index < size);

		return data[index];
	}


	int Size() const {
		return size;
	}


	int Capacity() const { return capacity;  }


	//Iterator begin()
	T* begin()
	{

		return data;
		//return Iterator(data);
	}

	//Iterator end() {
	T* end()
	{
		//return Iterator(data + size);
		return data + size;
	}

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
			memcpy(newBlock, data, sizeof(T) * size);


		


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