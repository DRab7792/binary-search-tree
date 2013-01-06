#include "bstNode.h"

class bst {
	private:
		bstNode *root;
	public:
		bst();
		bst(bstNode *newRoot);
		~bst();
		void deleteNode(bstNode *subtree);
		int findI(int search);
		int findR(int search);
		bool findRAux(int search, bstNode *subtree);
		int insertR(int newNode);
		int insertI(int newNode);
		bstNode *insertRAux(int newNode, bstNode *subtree);
};
