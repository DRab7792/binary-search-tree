#include <string>
#include <iostream>
#include "bst.h"
using namespace std;

bst::bst(){
}

bst::~bst(){
	deleteNode(root);
}

void bst::deleteNode(bstNode *subtree){
	if (subtree!=NULL){
		deleteNode(subtree->left);
		deleteNode(subtree->right);
		delete subtree;
	}
}

bst::bst(bstNode *newNode){
	root = newNode;
}

int bst::findR(int search){
	if (root==NULL){
		return 0;	
	}else {
		bool found = findRAux(search, root);
		if (found==true){
			return search;
		}else {
			return 0;
		}
	}
}

bool bst::findRAux(int search, bstNode *subtree){
	if (subtree==NULL){
		return false;
	}else if (search > subtree->element){
		return findRAux(search, subtree->right);
	}else if (search < subtree->element){
		return findRAux(search, subtree->left);
	}else {
		//cout << "found";
		return true;
	}
}

int bst::insertR(int newNode){
	if (root==NULL){
		root = new bstNode(newNode);
		return newNode;
	}else {
		bstNode *prevNode = insertRAux(newNode, root);
		if (prevNode!=NULL){
			if (newNode>prevNode->element){
				bstNode *tempNode = new bstNode(newNode);
				prevNode->right = tempNode;
			}else if (newNode<prevNode->element){
				bstNode *tempNode = new bstNode(newNode);
				prevNode->left = tempNode;
			}
			return newNode;
		}else{
			return 0;
		}	
	}	 
}

int bst::insertI(int newNode){
	bstNode *tempNode = root;
	bstNode *parent;
	bool found = false;
	while (!found && tempNode !=NULL){
		parent = tempNode;
		if (newNode < tempNode->element){
			tempNode = tempNode->left;
		}else if (newNode > tempNode->element){
			tempNode = tempNode->right;
		}else {
			found = true;
		}
	}
	if (!found){
		tempNode = new bstNode(newNode);
		if (parent==NULL){
			root = tempNode;
		}else if (newNode < parent->element){
			parent->left = tempNode;
		}else if (newNode > parent->element){
			parent->right = tempNode;
		}
		return newNode;
	}else {
		return 0;
	}
}

int bst::findI(int search){
	bool found = false;
	bstNode *tempNode = root;
	while (!found && tempNode!=NULL){
		if (search > tempNode->element){
			tempNode = tempNode->right;
		}else if (search < tempNode->element){
			tempNode = tempNode->left;
		}else {
			found = true;
		}
	}
	if (found == true){
		return search;
	}else {	
		return 0;
	}
}

bstNode *bst::insertRAux(int newNode, bstNode *subtree){
	if (newNode>subtree->element){
		if (subtree->right!=NULL){
			insertRAux(newNode, subtree->right);
		}else {
			return subtree;
		}
	}else if (newNode<subtree->element){
		if (subtree->right!=NULL){
			insertRAux(newNode, subtree->left);
		}else {
			return subtree;
		}
	}else if (newNode==subtree->element){
		return NULL;
	}
	
}
