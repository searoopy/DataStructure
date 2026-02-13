#pragma once




template<typename T>
class Node
{


	//연결 리스트 friend 지정.
	template<typename T>
	friend class LinkedList;



	//노드의 생성은 linkedlist에서만 가능하도록 private 로 지정.
private:

	Node()
		: data(), next(nullptr)
	{
	}

	Node(T data)
		: data(data), next(nullptr)
	{
	}

private:

	T data;


	Node* next = nullptr;


};