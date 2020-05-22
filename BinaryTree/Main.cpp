#include "BinaryTree.h"
#include "TreeNode.h"

using namespace std;


TreeNode* CreateMinimalBST(const int* array, const int start, const int end)
{
	if (end < start)
		return nullptr;
	const int mid = (start + end) / 2;
	auto bTree = new TreeNode(array[mid]);
	bTree->setLeft(CreateMinimalBST(array, start, mid - 1));
	bTree->setRight(CreateMinimalBST(array, mid + 1, end));
	return bTree;
}

int main()
{
	BinaryTree* node = new BinaryTree();
	node->Insert(9);
	node->Insert(4);
	node->Insert(19);
	node->Insert(8);
	node->Insert(5);
	node->Insert(13);
	delete node;
}
