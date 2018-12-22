//implementation of BST
#include "../include/BinarySearchTree.h"
//------------------------------
//	Protected Methods
//------------------------------

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode)
{
	if(subTreePtr==nullptr)
	{
		return newNode;
	}
	else if(subTreePtr->getItem() > newNode->getItem())
	{
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNode);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNode);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	
	return subTreePtr;
}

template<class ItemType>
 std::shared_ptr<BinaryNode<ItemType>>  BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& isSuccessful)
{
	return subTreePtr;
}

template<class ItemType>
 std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
	return nodePtr;
}

template<class ItemType>
 std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, ItemType& inorderSuccessor)
{
	return subTreePtr;
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType& target, bool& success) const
{
	if(subTreePtr == nullptr)
	{
		return nullptr;
	}
	
	else if(subTreePtr->getItem() == target)
	{
		success = true;
		return subTreePtr;
	}
	
	else if(subTreePtr->getItem() > target)
	{
		return findNode(subTreePtr->getLeftChildPtr(), target, success);
	}
	
	else
	{
		return findNode(subTreePtr->getRightChildPtr(), target, success);
	}
}

//------------------------------------
//	Constructor and Destructor
//------------------------------------

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) 
{
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
}

//------------------------------
//	Public Methods
//------------------------------

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return false;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	return this->getHeightHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
	return 0;
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcep)
{
	return 0;
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{
	std::shared_ptr<BinaryNode<ItemType>> newNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry);
	rootPtr = placeNode(rootPtr, newNodePtr);
	
	return true;
}
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& anEntry)
{
	return false;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException)
{
	bool success = false;
	std::shared_ptr<BinaryNode<ItemType>> tempPtr = findNode(rootPtr, anEntry, success);

	if(!success)
	{
		throw NotFoundException("could not find entry");
	}
	
	return tempPtr->getItem();
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
	return false;
}

//------------------------------
//	Public Traversals
//------------------------------

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	return this->preorder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	return this->inorder(visit, rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	return this->postorder(visit, rootPtr);
}

//------------------------------
//	Overloaded Operator
//------------------------------

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
}

