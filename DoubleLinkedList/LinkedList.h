#pragma once



#include "Node.h"

#include <iostream>




template<typename T>
class LinkedList
{
public:
	LinkedList()
		: first(new Node<T>() ),
		last( new Node<T>() ),
		count(0)
	{

		//처음과 마지막 노드 연결
		first->next = last;

		last->previous = first;



	}

	~LinkedList()
	{

		//if (_heapchk() != _HEAPOK)
		//{
		//	__debugbreak();
		//}

		Clear();

		//if (_heapchk() != _HEAPOK)
		//{
		//	__debugbreak();
		//}

		delete first;
		first = nullptr;

		//if (_heapchk() != _HEAPOK)
		//{
		//	__debugbreak();
		//}



		delete last;
		last = nullptr;


	/*	if (_heapchk() != _HEAPOK)
		{
			__debugbreak();
		}*/

	}


	void Clear()
	{
		//데이터를 갖는 척 항목 삭제.
		Node<T>* current = first->next;

		//마지막 노드 도달 전까지 반복.
		while (current && current != last)
		{
			//다음 노드 임시 저장.
			Node<T>* next = current->next;

			//현재 노드 삭제.
			delete current;

			//다음 노드로 이동.
			current = next;
		}

		//
		count = 0;

		//초기 상태로 리셋.
		first->next = last;
		last->previous = first;


	}



	//검색함수
	Node<T>* Find(const T& data)
	{
		Node<T>* current = first->next;

		while (current && current != last)
		{
			if (current->data == data)
			{
			
				return current;
			}

			//다음 노드 이동.
			current = current->next;
		}


		std::cout << "can't find the data.\n";
		return nullptr;
	}

	//중간에 삽입하는 함수
	//todo: 중간에 삽입하는 함수


	//첫 위치게 추가하는 함수.
	void InsertFirst(const T& data)
	{
		//새 노드 생성.
		Node<T>* newNode = new Node<T>();
		newNode->data = data;


		//포인터 정리.
		//새 노드의 다음 노드를 first->next(기존의 첫노드).
		//이전 first->next를 새 노드로 설정.
		Node<T>* next = first->next;
		newNode->next = next;
		next->previous = newNode;
		
		//first->next 노드를 새노드로.
		//새 노드의 이전 노드를 first로 설정
		first->next = newNode;
		newNode->previous = first;


		++count;

	}


	//마지막 위치에 항목을 추가하는 함수
	void InsertLast(const T& data)
	{
		//새 노드 생성.
		Node<T>* newNode = new Node<T>();
		newNode->data = data;


		Node<T>* previous = last->previous;
		previous->next = newNode;
		newNode->previous = previous;


		newNode->next = last;
		last->previous = newNode;

		++count;
	}

	void Print()
	{
		Node<T>* current = first->next;

		std::cout << "List item count : " << count << "\n";

		while (current != last)
		{
			//노드의 데이터 출력.
			std::cout << "Item: " << current->data << "\n";

			//다음 노드로 이동.
			current = current->next;
		}
	}

	void Delete(const T& data)
	{
		if (count == 0)
		{
			std::cout << "List is empty\n";
			return;
		}

		//삭제할 노드 검색.(순방향검색)
		Node<T>* delNode = Find(data);

		if (!delNode)
		{
			std::cout << "Failed to find data to delete.\n";
			return;
		}


		//포인터 정리....
		delNode->previous->next = delNode->next;
		delNode->next->previous = delNode->previous;

		delete delNode;
		delNode = nullptr;

		--count;






	}



private:


	Node<T>* first = nullptr;
	Node<T>* last = nullptr;


	//저장된 항목수
	int count = 0;

};