#include <iostream>
#include "BinarySearchTree.h"


int main()
{
	BinarySearchTree<int> tree;


	tree.InsertNode(10);
	tree.InsertNode(5);
	tree.InsertNode(15);
	tree.InsertNode(30);
	tree.InsertNode(31);
	tree.InsertNode(32);
	tree.InsertNode(33);
	tree.InsertNode(34);
	tree.InsertNode(14);
	tree.InsertNode(24);
	tree.InsertNode(44);
	tree.InsertNode(1);
	tree.InsertNode(3);

	//ªË¡¶
	tree.DeleteNode(30);



	std::cin.get();
}