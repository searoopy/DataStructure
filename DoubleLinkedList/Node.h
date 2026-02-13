#pragma once

template<typename T>
class Node
{
	template<typename T>
	friend class LinkedList;


public:
	//»ý¼ºÀÚ
	Node()
		:data(), next(nullptr), previous(nullptr)
	{ }



	
private:
	T data;


	Node<T>* next = nullptr;
	Node<T>* previous = nullptr;
};