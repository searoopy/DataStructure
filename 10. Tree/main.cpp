#include "Container/Tree.h"
#include <iostream>

int main()
{

	//Node<int>* parent = new Node<int>(10);
	//Node<int>* child = new Node<int>(5);

	//parent->AddChild(child);
	//child->SetParent(parent);


	//parent->RemoveChild(child);




	Tree<int> tree(101);


	tree.AddChild(101, 6);
	tree.AddChild(6, 9);
	tree.AddChild(6, 7);
	tree.AddChild(9, 8);
	tree.AddChild(2, 1);
	tree.AddChild(2, 111);
	tree.AddChild(2, 3);
	tree.AddChild(3, 8);
	tree.AddChild(3, 7);



	//검색 테스트
	Node<int>* outNode = nullptr;
	if (tree.Find(6, outNode))
	{
		int number2 = 30;

	}


	////삭제 테스트
	//if (tree.Remove(9))
	//{
	//	int nubmer3 = 30;
	//}



	tree.PreorderTraversal();

	std::cin.get();


}