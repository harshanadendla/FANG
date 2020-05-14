#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;

  BinaryTree(int value);
};

void mutate(BinaryTree *node,BinaryTree * parent,bool isLeftChild);

BinaryTree *rightSiblingTree(BinaryTree *root) {
	mutate(root,NULL,false);
  return root;
}

void mutate(BinaryTree *node,BinaryTree *parent,bool isLeftChild) {
	if (node==NULL) {
		return ;
	}
	
	auto left=node->left;
	auto right=node->right;
	mutate(left,node,true);
	if (parent==NULL) {
		node->right=NULL;
	} else if (isLeftChild) {
		node->right=parent->right;
	} else {
		if (parent->right==NULL) {
			node->right=NULL;
		} else {
			node->right=parent->right->left;
		}
	}
	mutate(right,node,false);
}