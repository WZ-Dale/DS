#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	struct Node *left;
	struct Node *right;
	char value;
}	Node;
//遍历树(前序,中序,后序)
void Preorder(Node *root) {
	if (root != NULL) {
		printf("%c ", root->value);
		Preorder(root->left);
		Preorder(root->right);
	}
}
void Inorder(Node *root) {
	if (root != NULL) {
		Inorder(root->left);
		printf("%c ", root->value);
		Inorder(root->right);
	}
}
void Postorder(Node *root) {
	if (root != NULL) {
		Postorder(root->left);
		Postorder(root->right);
		printf("%c ", root->value);
	}
}
//构建树
Node * CreateNode(char v) {
	Node * node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->left = node->right = NULL;
	return node;
}
Node * CreateTree() {
	Node *a = CreateNode('A');
	Node *b = CreateNode('B');
	Node *c = CreateNode('C');
	Node *d = CreateNode('D');
	Node *e = CreateNode('E');
	Node *f = CreateNode('F');
	Node *g = CreateNode('G');
	Node *h = CreateNode('H');

	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->left = f; c->right = g;
	// d
	e->right = h;

	return a;
}
//求结点个数
int GetSize(Node *root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int left = GetSize(root->left);
		int right = GetSize(root->right);

		return left + right + 1;
	}
}
//求叶子结点个数
int GetLeafSize(Node *root) {
	if (root == NULL) {
		return 0;
	}
	else if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	else {
		return GetLeafSize(root->left) + GetLeafSize(root->right);
	}
}
//求树的高度
int GetHeight(Node *root) {
	if (root == NULL) {
		return 0;
	}
	else {
		// 不要多次用同样的参数调用函数
		int left = GetHeight(root->left) + 1;
		int right = GetHeight(root->right) + 1;

		return (left > right ? left : right);
	}
}
//求k层的节点个数
int GetKLevelSize(Node *root, int k) {
	if (root == NULL) {
		return 0;
	}
	else if (k == 1) {
		return 1;
	}
	else {
		int left = GetKLevelSize(root->left, k - 1);
		int right = GetKLevelSize(root->right, k - 1);
		return left + right;
	}
}
//普通二叉树查找
	// 如果找到了，返回 v 所在结点的地址
	// 如果没找到，返回 NULL
	// 先去根里找
	// 如果没找到，再去左子树找
	// 如果还没找到，再去右子树找
	// 在空树里找的结果，一定找不到，return NULL
Node * Find(Node *root, char v) {
	if (root == NULL) {
		// 空树
		return NULL;
	}
	else if (root->value == v) {
		// 根就是
		return root;
	}

	Node *node = Find(root->left, v);
	if (node != NULL) {
		return node;
	}

	node = Find(root->right, v);
	if (node != NULL) {
		return node;
	}
	else {
		return NULL;
	}
}
//遍历树,返回数组

//判断两树是否相等
bool isSame(Node*p, Node*q) {
	if (p == NULL && q == NULL) {
		return true;
	}

	if (p == NULL || q == NULL) {
		return false;
	}

	return p->value == q->value
		&& isSame(p->left, q->left)
		&& isSame(p->right, q->right);
}
//判断两树是否镜像
bool preorder(Node*root, Node*t) {
	if (root != NULL) {
		// 根
		if (isSame(root, t)) {
			return true;
		}
		if (preorder(root->left, t) == true) {
			return true;
		}

		return preorder(root->right, t);
	}

	return false;
}
//判断树是否对称

//判断一个树是否是另一个树的子树
bool isSubtree(Node* s, Node* t) {
	return preorder(s, t);
}
void Test2() {
	Node *root = CreateTree();
	Node *e = CreateNode('E');
	Node *h = CreateNode('H');
	Node *i = CreateNode('I');
	e->left = NULL; e->right = h;
	h->right = i;

	if (isSubtree(root, e)) {
		printf("是子树\n");
	}
	else {
		printf("不是子树\n");
	}
}
//判断树是否是平衡二叉树

//根据前序(ABDF####C#E#G)构建二叉树
Node * CreateTree1(char preorder[], int size, int *used) {
	if (size == 0) {
		*used = 0;
		return NULL;
	}
	if (preorder[0] == '#') {
		*used = 1;
		return NULL;
	}
	Node *root = malloc(sizeof(Node));
	root->value = preorder[0];

	int leftUsed;
	root->left = CreateTree1(preorder + 1, size - 1, &leftUsed);

	int rightUsed;
	root->right = CreateTree1(
		preorder + 1 + leftUsed,
		size - 1 - leftUsed,
		&rightUsed);
	*used = 1 + leftUsed + rightUsed;
	return root;
}




typedef struct Result {
	Node *root;
	int used;
}	Result;

Result CreateTree2(char preorder[], int size) {
	Result r;
	if (size == 0) {
		r.root = NULL;
		r.used = 0;
		return r;
	}

	if (preorder[0] == '#') {
		r.root = NULL;
		r.used = 1;
		return r;
	}

	Node *root = malloc(sizeof(Node));
	root->value = preorder[0];

	Result leftR = CreateTree2(preorder + 1, size - 1);
	Result rightR = CreateTree2(
		preorder + 1 + leftR.used,
		size - 1 - leftR.used);

	root->left = leftR.root;
	root->right = rightR.root;

	r.root = root;
	r.used = 1 + leftR.used + rightR.used;

	return r;
}

void Test3() {
	char *preorder = "ABDF####C#E#G";
	int size = strlen(preorder);
	int used;
	Node *root = CreateTree1(preorder, size, &used);

	Preorder(root);
}
