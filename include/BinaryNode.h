/** A class of nodes for a link-based binary tree. @file BinaryNode.h */
#ifndef _BINARY_NODE
#define _BINARY_NODE
#include <memory>
template<class ItemType> class BinaryNode
{
private:
ItemType item;
std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;
std::shared_ptr<BinaryNode<ItemType>> rightChildPtr; // Pointer to right child
public:
BinaryNode();
BinaryNode(const ItemType& anItem); 
BinaryNode(const ItemType& anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> rightPtr);
void setItem(const ItemType& anItem); 
ItemType getItem() const;
bool isLeaf() const;
std::shared_ptr<BinaryNode<ItemType>> getLeftChildPtr() const;
std::shared_ptr<BinaryNode<ItemType>> getRightChildPtr() const;
void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
}; // end BinaryNode

//#include "../src/BinaryNode.cpp"
#endif
