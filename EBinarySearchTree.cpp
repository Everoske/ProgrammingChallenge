#include "EBinarySearchTree.h"
#include <iostream>

EBinarySearchTree::EBinarySearchTree()
{
	root = nullptr;
}

EBinarySearchTree::EBinarySearchTree(float rValue)
{
	root = new BSTNode();
	root->value = rValue;
}

void EBinarySearchTree::insert(float nValue)
{
	if (root == nullptr)
	{
		root = new BSTNode();
		root->value = nValue;
		return;
	}

	insert(nValue, root);
}

std::vector<float> EBinarySearchTree::toSortedVector()
{
	std::vector<float> sortedVector{};
	inOrderTraversal(root, sortedVector);
	return sortedVector;
}

void EBinarySearchTree::insert(float nValue, BSTNode* parent)
{
	if (parent->value > nValue)
	{
		if (parent->left == nullptr)
		{
			parent->left = new BSTNode();
			parent->left->value = nValue;
		}
		else
		{
			insert(nValue, parent->left);
		}
	}
	else
	{
		if (parent->right == nullptr)
		{
			parent->right = new BSTNode();
			parent->right->value = nValue;
		}
		else
		{
			insert(nValue, parent->right);
		}
	}
}

void EBinarySearchTree::inOrderTraversal(BSTNode* node, std::vector<float>& sVector)
{
	if (node == nullptr) return;

	inOrderTraversal(node->left, sVector);
	sVector.push_back(node->value);
	inOrderTraversal(node->right, sVector);
}
