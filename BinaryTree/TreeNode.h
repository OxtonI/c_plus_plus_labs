#pragma once
class TreeNode
{
public:

	TreeNode();
	TreeNode(int value);
	~TreeNode();

	int getValue();
	void setValue(int val);
	TreeNode* getLeft();
	void setLeft(TreeNode* lef);
	TreeNode* getRight();
	void setRight(TreeNode* righ);

private:
	int value;
	TreeNode* left;
	TreeNode* right;
};