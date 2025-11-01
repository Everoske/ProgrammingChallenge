#ifndef EBINARYSEARCHTREE_H
#define EBINARYSEARCHTREE_H

#include <vector>

struct BSTNode
{
	float value;
	BSTNode* left;
	BSTNode* right;
};

class EBinarySearchTree
{
public:
	EBinarySearchTree();
	EBinarySearchTree(float rValue);
	void insert(float nValue);
	std::vector<float> toSortedVector();
private:
	BSTNode* root;
	void insert(float nValue, BSTNode* node);
	void inOrderTraversal(BSTNode* node, std::vector<float>& sVector);
};

#endif