//#include "../include/BinarySearchTree.h"
#include "fix.cpp"
#include <iostream>
#include "time.h"

template<class ItemType>
void visit(ItemType& item)
{
	std::cout << " " << item;
}

int main()
{
	srand(time(NULL));

	BinarySearchTree<int> bst;	

	for(int i = 0; i < 100; i++)
	{
		int temp = rand() % 200;
		bst.add(temp);
	}

	std::cout << "Tree Height" << std::endl;
	std::cout << bst.getHeight() << std::endl;
	std::cout << "\nInorder" << std::endl;
	bst.inorderTraverse(visit);
	std::cout << "\nPreorder" << std::endl;
	bst.preorderTraverse(visit);
	std::cout << "\nPostorder"  << std::endl;
	bst.postorderTraverse(visit);
	std::cout << std::endl;
	return 0;
}
