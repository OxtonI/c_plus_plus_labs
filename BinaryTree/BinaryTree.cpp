#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
	root = nullptr;
}

BinaryTree::BinaryTree(int value)
{
	root->setValue(0);
}

void BinaryTree::DeleteNodesTree(TreeNode* leàf)
{
	if (leàf != nullptr) {
		DeleteNodesTree(leàf->getLeft());
		DeleteNodesTree(leàf->getRight());
		delete leàf;
	}
}

void BinaryTree::DeleteNodesTree()
{
	DeleteNodesTree(root);
}

void BinaryTree::Insert(int key, TreeNode* leaf)
{
	if (key < leaf->getValue()) {
		if (leaf->getLeft() != nullptr) {
			Insert(key, leaf->getLeft());
		}
		else {
			leaf->setLeft(new TreeNode());
			leaf->getLeft()->setValue(key);
			leaf->getLeft()->setLeft(nullptr);
			leaf->getLeft()->setRight(nullptr);
		}
	}
	else if (key >= leaf->getValue()) {
		if (leaf->getRight() != nullptr) {
			Insert(key, leaf->getRight());
		}
		else {
			leaf->setRight(new TreeNode());
			leaf->getRight()->setValue(key);
			leaf->getRight()->setRight(nullptr);
			leaf->getRight()->setLeft(nullptr);
		}
	}
}

void BinaryTree::Insert(int key)
{
	if (root != nullptr) {
		Insert(key, root);
	}
	else {
		root = new TreeNode;
		root->setValue(key);
		root->setRight(nullptr);
		root->setLeft(nullptr);
	}
}

TreeNode* BinaryTree::Search(int key, TreeNode* leaf)
{
	if (leaf != nullptr) {
		if (key == leaf->getValue()) { return leaf; }
		if (key < leaf->getValue()) { return Search(key, leaf->getLeft()); }
		else { return Search(key, leaf->getRight()); }
	}
	else { return nullptr; }
}

TreeNode* BinaryTree::Search(int key)
{
	return Search(key, root);
}


BinaryTree::~BinaryTree()
{
	DeleteNodesTree();
}
