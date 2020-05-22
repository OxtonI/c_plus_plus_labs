#include "TreeNode.h"


TreeNode::TreeNode()
{
	value = 0;
	left = nullptr;
	right = nullptr;
}

TreeNode::TreeNode(int value)
{
	this->value = value;
	left = nullptr;
	right = nullptr;
}

int TreeNode::getValue() { return value; }
void TreeNode::setValue(int val) { value = val; }
TreeNode* TreeNode::getLeft() { return left; }
void TreeNode::setLeft(TreeNode* leaf) { left = leaf; }
TreeNode* TreeNode::getRight() { return right; }
void TreeNode::setRight(TreeNode* leaf) { right = leaf; }


TreeNode::~TreeNode()
{
}
