//Binary node tree implementation
#include "../include/BinaryNodeTree.h"
//------------------------------
//	Protected Methods
//------------------------------

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	if(subTreePtr == nullptr)
		return 0;
	else
		return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
} //end getHeightHelper

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	return 0;
} //end getNumberOfNodesHelper

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
std::shared_ptr<BinaryNode<ItemType>> newTreePtr = nullptr;

// Copy tree nodes during a preorder traversal
if (treePtr != nullptr) 
	{
		// Copy node
		std::shared_ptr<BinaryNode<ItemType>> newTreePtr = std::make_shared<BinaryNode<ItemType>>(treePtr->getItem());
        	newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr())); 
	} // end if
	// Else tree is empty (newTreePtr is nullptr)

return newTreePtr; 
} // end copyTree

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{

	if(subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
	}
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
	if (subTreePtr == nullptr)
	return newNodePtr;

	else
	{
		std::shared_ptr<BinaryNode<ItemType>> leftPtr = subTreePtr->getLeftChildPtr();
		std::shared_ptr<BinaryNode<ItemType>> rightPtr = subTreePtr->getRightChildPtr();

		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) 
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
            		subTreePtr->setRightChildPtr(rightPtr);
          	}
		else
		{
		leftPtr = balancedAdd(leftPtr, newNodePtr); subTreePtr->setLeftChildPtr(leftPtr);
		} // end if
		
		return subTreePtr;
	}
}// end balancedAdd


template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& success)
{
	return nullptr;
}// end removeValue

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
	return nullptr;
}// end moveValuesUpTree

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target, bool& success) const
{
	return nullptr;
}// end findNode

template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if(treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
	}	
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	if(treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	}
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
	    if(treePtr != nullptr)
        {
                preorder(visit, treePtr->getLeftChildPtr());
                preorder(visit, treePtr->getRightChildPtr());
        	ItemType theItem = treePtr->getItem();
                visit(theItem);
	}
}
//---------------------------------------
//	Constructors and Destructors
//---------------------------------------

template<class ItemType> 
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr) 
{
} // end default constructor

template<class ItemType> 
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem) 
{
	std::shared_ptr<BinaryNode<ItemType>> rootPtr = std::make_shared<BinaryNode<ItemType>>(rootItem);
//	item = rootItem; 
} // end constructor

template<class ItemType> 
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem, const std::shared_ptr<BinaryNode<ItemType>> leftTreePtr, const std::shared_ptr<BinaryNode<ItemType>> rightTreePtr)
{
std::shared_ptr<BinaryNode<ItemType>> rootPtr = std::make_shared<BinaryNode<ItemType>>(rootItem, copyTree(leftTreePtr->rootPtr),
copyTree(rightTreePtr->rootPtr));
	rootPtr->item = rootItem;
	rootPtr->leftChildPtr = copyTree(leftTreePtr->rootPtr);
	rootPtr->rightChildPtr = copyTree(rightTreePtr->rootPtr);
}// end overloaded constructor

template<class ItemType> 
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr) 
{
rootPtr = copyTree(treePtr.rootPtr);
} // end copy constructor

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}// end destructor


//------------------------------
//	Public Interface
//------------------------------

template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
	if(rootPtr == nullptr)
		return true;
	return false;
}// end isEmpty

template<class ItemType>
int  BinaryNodeTree<ItemType>::getHeight() const
{
	return getHeightHelper(rootPtr);
}// end getHeight

template<class ItemType>
int  BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
	return 0;
}// end getNumberOfNodes

template<class ItemType>
ItemType  BinaryNodeTree<ItemType>::getRootData() const throw(PrecondViolatedExcep)
{
	return 0;
}// end getRootData

template<class ItemType>
void  BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
}// end setRootData

template<class ItemType>
bool  BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
	std::shared_ptr<BinaryNode<ItemType>> newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);

	return true;
}// end add

template<class ItemType> 
bool  BinaryNodeTree<ItemType>::remove(const ItemType& data)
{
	return false;
}// end remove

template<class ItemType> 
void  BinaryNodeTree<ItemType>::clear()
{
}// end clear

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException)
{
	return 0;
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const
{
	return false;
}

//--------------------------------------------------
//	Public Traversals
//--------------------------------------------------

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	preorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	inorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	postorder(visit, rootPtr);
}


//--------------------------------------------------
//	Overloaded Operator
//--------------------------------------------------

template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType>& rightHandSide)
{
	return 0;
}
