#define WIN32_LEAN_AND_MEAN


#include <iostream>

#include <Windows.h>

#include <WinSock2.h>

#include <cassert>

//템플릿으로 배열 만들기
template<typename T, size_t size =10>
class Array
{
public:
	size_t Size() const
	{
		return size;
	}


	//배열 연산자 오버로딩.
	T& operator[](size_t index)
	{

		//어써트.
		assert(index < 0 || index >= size);



		return data[index];
	}

	const T& operator[](size_t index) const
	{
		return data[index];
	}

private:
	T data[size] = {};
};

int main()
{
	Array<int, 10> array;
	array[3] = 20;


	//const 접근
	//Array<int, 10>& arrayReference = array;
	auto& arrayReference = array;

	std::cin.get();

}