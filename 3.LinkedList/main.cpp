#include "linkedlist/Linkedlist.h"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include <forward_list>


int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//_CrtSetBreakAlloc(164);

	LinkedList<int> list;


	std::forward_list<int> stlList;
	stlList.emplace_after(stlList.begin(), 10);

	list.Insert(1);
	list.Insert(2);
	list.Insert(3);

	list.Print();

	std::cout << "삭제후 출력\n";
	list.Delete(3);


	list.Print();

	std::cin.get();



}