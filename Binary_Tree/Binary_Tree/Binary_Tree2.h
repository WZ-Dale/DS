#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct Node {
	char value;
	struct Node *left;
	struct Node *right;
}	Node;
/**
* @���� IN preorder: �������('#')��ǰ����������
* @���� IN size: ǰ������������ó���
* @���� OUT pUsed: ���ش�����������ʹ�õ������ַ�����
*
* @���� �����õ����ĸ�����ַ
*/
// ʹ�ø������й���������
Node * CreateTree(char preorder[], int size, int *pUsed) {
	if (size == 0) {
		// �Ѳ���
		*pUsed = 0;
		return NULL;
	}
	else if (preorder[0] == '#') {
		// �Ѳ���
		*pUsed = 1;
		return NULL;
	}
	else {
		// ��
		Node *root = (Node *)malloc(sizeof(Node));
		root->value = preorder[0];
		// ������
		int leftUsed;		// �������洴���������õ��ĸ���
		int rightUsed;		// �������洴���������õ��ĸ���
		root->left = CreateTree(preorder + 1, size - 1, &leftUsed); // preorder + 1 ����������
		root->right = CreateTree(preorder + 1 + leftUsed, size - 1 - leftUsed, &rightUsed); // �Ѳ���

		// �Ѳ���
		*pUsed = 1 + leftUsed + rightUsed; // ���õ� + �������õ� + �������õ�
		return root;
	}
}
void Test2() {
	char *preorder = "ABD##E#H##CF##G";
	int size = strlen(preorder);
	int used;
	Node *root = CreateTree(preorder, size, &used);
	assert(used == size);
}

// Сʵ��
void TestAddress(int n, int *pUsed) {
	if (n == 1) {
		*pUsed = n * 1000;
		return;
	}
	*pUsed = n * 1000;
	TestAddress(n - 1, pUsed + 3);
}
void Test1() {
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;
	int g = 7;
	TestAddress(3, &d);
	printf("hello world\n");
}

// �ĸ����Ի�ԭ������:
// ǰ�� + ���� (������)
// ǰ�� + ���� (����)
// ���� + ���� (����)
// ǰ��		�Ҹ����	preorder[0]
// ����		�Ҹ����	preorder[size - 1]
// ����		�ָ������������

// 1.ǰ�� + ���� ��ԭ��
int Find(char array[], int size, char v) {			// ��ǰ����������λ��
	for (int i = 0; i < size; i++) {
		if (array[i] == v) {
			return i;
		}
	}
	return -1;
}
Node * buildTree(char preorder[], char inorder[], int size) {
	if (size == 0) {
		return NULL;
	}
	char rootValue = preorder[0];
	int leftSize = Find(inorder, size, rootValue);		// ��ǰ����������λ��
	// ��
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	// ������
	root->left = buildTree(preorder + 1, inorder, leftSize);
	// ������
	root->right = buildTree(preorder + 1 + leftSize, inorder + leftSize + 1, size - 1 - leftSize);
	return root;
}
void Test3() {
	char *preorder = "ABDEHCFG";	//ǰ��
	char *inorder = "DBEHAFCG";		//����
	int size = strlen(preorder);
	Node *root = buildTree(preorder, inorder, size);
}

// 2.���� + ���� ��ԭ��
int Find2(char array[], int size, char value) {			// �Һ�����������λ��
	for (int i = 0; i < size; i++) {
		if (array[i] == value) {
			return i;
		}
	}
	return -1;
}
// inorder	 D B E H A F C G
// postorder D H E B F G C A
Node * buildTree2(char inorder[], char postorder[], int size) {
	if (size == 0) {
		return NULL;
	}
	char rootValue = postorder[size - 1];
	int leftSize = Find2(inorder, size, rootValue);			// �Һ�����������λ��
	//��
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	//������
	root->left = buildTree2(inorder, postorder, leftSize);
	//������
	root->right = buildTree2(inorder + leftSize + 1, postorder + leftSize, size - 1 - leftSize);
	return root;
}



// һ�����õݹ�ʵ�ֵ�ǰ��/����/����		(������ȱ���)		����������ϵͳ����ջ		�ص�
// �������ö���ʵ�ֶ������Ĳ������		(������ȱ���)
// �����Լ���ջʵ��ǰ��/����/����		�ǵݹ鷽ʽ										�ѵ�

#include <queue>
// �������
void LevelOrder(Node *root) {
	if (root == NULL) {
		printf("\n");
	}
	// ����
	std::queue<Node *> q;
	q.push(root);
	while (!q.empty()) {
		Node *front = q.front();
		q.pop();
		printf("%c ", front->value);
		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL) {
			q.push(front->right);
		}
	}
	printf("\n");
}
void Test4() {
	char *inorder = "DBEHAFCG";
	char *postorder = "DHEBFGCA";
	int size = strlen(inorder);
	Node *root = buildTree2(inorder, postorder, size);
	LevelOrder(root);
}

// �ж϶������Ƿ��� ��ȫ������
bool IsComplete(Node *root) {
	std::queue<Node *> q;
	q.push(root);
	while (true) {
		Node *front = q.front();
		q.pop();
		if (front == NULL) {
			break;
		}
		// ����������ս��Ҳ������
		q.push(front->left);
		q.push(front->right);
	}
	// �ж�������ʣ�������Ƿ�ȫ�� NULL
	while (!q.empty()) {
		Node *front = q.front();
		q.pop();
		if (front != NULL) {
			return false;
		}
	}
	// ���ж��� NULL
	return true;
}
void Test5() {
	char *inorder = "DBEAC";
	char *postorder = "DEBCA";
	int size = strlen(inorder);
	Node *root = buildTree2(inorder, postorder, size);
	LevelOrder(root);
	if (IsComplete(root)) {
		printf("����ȫ������\n");
	}
	else {
		printf("������ȫ������\n");
	}
}

// �ǵݹ�ʵ��ǰ��
// �ݹ�ȱ��: 1.�������Ȳ� 2.����ջ�Ĵ�С�Ƚ��鷳(ֻ�ܱ����ڼ����)
// �ǵݹ� �Զ����ջ + ѭ��
#include <stack>
// �ǵݹ�Ķ�����д��(��ջд)
// 1.(ǰ�����)
void PreOrderNoR(Node *root) {
	std::stack<Node *> s;
	Node *cur = root;
	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			printf("%c ", cur->value);
			s.push(cur);
			cur = cur->left;
		}
		Node *top = s.top(); s.pop();
		cur = top->right;
	}
}
void Test6() {
	char *inorder = "DBEAC";
	char *postorder = "DEBCA";
	int size = strlen(inorder);
	Node *root = buildTree2(inorder, postorder, size);
	PreOrderNoR(root);
}
// 2.(�������)
void InOrderNoR(Node *root) {
	std::stack<Node *> s;
	Node *cur = root;
	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}
		Node *top = s.top(); s.pop();
		printf("%c ", top->value);			// �Ѵ�ӡ�����ӵ�����Ϳ�����
		cur = top->right;
	}
}
// 3.(�������)
void PostOrderNoR(Node *root) {
	std::stack<Node *> s;
	Node *cur = root;
	Node *last = NULL;
	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			// ��һ������
			s.push(cur);
			cur = cur->left;
		}
		Node *top = s.top();
		// �Ҳ�֪���ǵڶ����������ǵ���������
		if (top->right == NULL) {
			printf("%c ", top->value);
			s.pop();
			last = top;
		}
		else if (top->right == last) {
			printf("%c ", top->value);
			s.pop();
			last = top;
		}
		else {
			cur = top->right;
		}
	}
}

// �����������


// ����������	�����	AVL��


// ����������ת������˫������
Node *prev = NULL;
// ��֤�������˳����øú���
void NodeToDoublyLink(Node *node) {
	node->left = prev;	// node->prev = prev;
	if (prev != NULL) {
		prev->right = node;	// prev->next = node;
	}
	prev = node;
}
void InOrder(Node *root) {
	if (root != NULL) {
		InOrder(root->left);
		// �� root
		NodeToDoublyLink(root);
		InOrder(root->right);
	}
}
