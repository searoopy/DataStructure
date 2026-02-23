#include <iostream>
#include "queue.h"

int main()
{


	Queue<int> queue;

	const int count = 10;
	for (int i = 0; i < count; ++i)
	{
		queue.Enqueue(i+1);
	}


	queue.Print();


	//°ª ÃßÃâ.
	int value;
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);


	queue.Print();

	queue.Enqueue(11);
	queue.Enqueue(12);


	queue.Print();

	std::cin.get();
}