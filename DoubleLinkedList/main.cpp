


#include <iostream>
#include "LinkedList.h"


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>



int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);





	LinkedList<int> list;

	for (int i = 0; i < 10; ++i)
	{
		list.InsertLast((i + 1) * 10);
	}




	std::cout << "리스트 추가후 출력\n";
	list.Print();


	list.Delete(20);



	std::cout << "리스트 제거후 출력\n";
	list.Print();


	std::cin.get();
}
