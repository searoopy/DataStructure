#pragma once



template<typename T, int capacity = 10 >

class Stack
{

public:
	//생성자
	Stack()
		: top(0)
	{
	}



	//스택에 넣기
	bool Push(const T& value)
	{
		if (IsFull())
		{

			std::cout << "stack is full\n";
			return false;
		}


		data[top] = value;
		++top;
		return true;
	}

	//삭제 함수
	bool Pop(T& outValue)
	{
		//스택이 빈 경우에는 추출실패.
		if (IsEmpty())
		{
			return false;
		}

		--top;
		outValue = data[top];
		return true;
	}


	//getter.
	inline int Count() const { return top; }

	//스택이 비었는지 확인.
	inline bool IsEmpty() const { return top == 0; }

	inline bool IsFull() const { return top >= capacity;  }

private:
	// 스택 비우는 함수.
	void Clear()
	{
		top = 0;
	}







private:
	//정적 배열로 데이터 관리.
	T data[capacity] = {};


	//스택 상단을 가릿키는 위치값.
	int top = 0;
};