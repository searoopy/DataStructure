#pragma once

template<typename T>
class Node
{
	//friend 선언.
	template<typename T>
	friend class BinarySearchTree;

public:
	Node(const T& data,
		Node<T>* const parent = nullptr)
		: data(data), parent(parent)
	{
	}



private:
	T data = T();


	//부모 노드
	Node<T>* parent = nullptr;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;


}

;