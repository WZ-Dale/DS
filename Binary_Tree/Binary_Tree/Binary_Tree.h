#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
}	Node;

// 根 左子树 右子树
void preorderTraversal(Node *root) {
	// 空树
	if (root == NULL) {
		return;
	}
	printf("%d ", root->value);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}


// 左子树 根 右子树
void inorderTraversal(Node *root) {
	// 空树
	if (root == NULL) {
		return;
	}
	inorderTraversal(root->left);
	printf("%d ", root->value);
	inorderTraversal(root->right);
}


// 左子树 右子树 根
void postorderTraversal(Node *root) {
	// 空树
	if (root == NULL) {
		return;
	}
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ", root->value);
}

//计算结点个数1
int count = 0;
void Size2(Node *root) {
	if (root == NULL) { 
		return; 
	}
	Size2(root->left);
	count++;
	Size2(root->right);
}

//计算结点个数2
int Size(Node *root) {
	if (root == NULL) {
		return 0;
	}
	return Size(root->left) + Size(root->right) + 1;
}