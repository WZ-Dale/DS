#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
}	Node;

// �� ������ ������
void preorderTraversal(Node *root) {
	// ����
	if (root == NULL) {
		return;
	}
	printf("%d ", root->value);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}


// ������ �� ������
void inorderTraversal(Node *root) {
	// ����
	if (root == NULL) {
		return;
	}
	inorderTraversal(root->left);
	printf("%d ", root->value);
	inorderTraversal(root->right);
}


// ������ ������ ��
void postorderTraversal(Node *root) {
	// ����
	if (root == NULL) {
		return;
	}
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ", root->value);
}

//���������1
int count = 0;
void Size2(Node *root) {
	if (root == NULL) { 
		return; 
	}
	Size2(root->left);
	count++;
	Size2(root->right);
}

//���������2
int Size(Node *root) {
	if (root == NULL) {
		return 0;
	}
	return Size(root->left) + Size(root->right) + 1;
}