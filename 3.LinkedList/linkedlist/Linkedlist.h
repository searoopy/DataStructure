#pragma once

#include "Node.h"

template<typename T>
class LinkedList
{
public:

	//타입 알리아싱 지정
	using NodeType = Node<T>*;


public:
	LinkedList()
		: head(nullptr), count(0)
	{

	}


private:

	//Node<T>* head = nullptr;
	NodeType head = nullptr;



	int count = 0;




};