#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;

  BinaryTree(int value, BinaryTree *parent = NULL);
  void insert(vector<int> values, int i = 0);
};

void iterativeInOrderTraversal(BinaryTree *tree,
                               void (*callback)(BinaryTree *tree)) {
	BinaryTree *previousNode=NULL;
	BinaryTree *currentNode=tree;
	while (currentNode != NULL) {
		BinaryTree * nextNode;
		if (previousNode==NULL || previousNode== currentNode->parent) {
			if (currentNode->left!=NULL) {
				nextNode=currentNode->left;
			} else {
				(*callback)(currentNode);
				nextNode=currentNode->right != NULL ? currentNode->right
					: currentNode->parent;
			}
		} else if (previousNode==currentNode->left) {
			(*callback)(currentNode);
			nextNode=currentNode->right!=NULL?currentNode->right:currentNode->parent;			
		} else {
			nextNode=currentNode->parent;
		}
		previousNode=currentNode;
		currentNode=nextNode;
	}
}
