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
* @参数 IN preorder: 保存带空('#')的前序序列数组
* @参数 IN size: 前序序列数组可用长度
* @参数 OUT pUsed: 返回创建树过程中使用的序列字符长度
*
* @返回 创建好的树的根结点地址
*/
// 使用给定序列构建二叉树
Node * CreateTree(char preorder[], int size, int *pUsed) {
	if (size == 0) {
		// 已补充
		*pUsed = 0;
		return NULL;
	}
	else if (preorder[0] == '#') {
		// 已补充
		*pUsed = 1;
		return NULL;
	}
	else {
		// 根
		Node *root = (Node *)malloc(sizeof(Node));
		root->value = preorder[0];
		// 左子树
		int leftUsed;		// 用来保存创建左子树用掉的个数
		int rightUsed;		// 用来保存创建右子树用掉的个数
		root->left = CreateTree(preorder + 1, size - 1, &leftUsed); // preorder + 1 用于跳过根
		root->right = CreateTree(preorder + 1 + leftUsed, size - 1 - leftUsed, &rightUsed); // 已补充

		// 已补充
		*pUsed = 1 + leftUsed + rightUsed; // 根用掉 + 左子树用掉 + 右子树用掉
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

// 小实验
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

// 哪个可以还原二叉树:
// 前序 + 后序 (不可以)
// 前序 + 中序 (可以)
// 后序 + 中序 (可以)
// 前序		找根最方便	preorder[0]
// 后序		找根最方便	preorder[size - 1]
// 中序		分割左右子树最方便

// 1.前序 + 中序 还原树
int Find(char array[], int size, char v) {			// 找前序根在中序的位置
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
	int leftSize = Find(inorder, size, rootValue);		// 找前序根在中序的位置
	// 根
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	// 左子树
	root->left = buildTree(preorder + 1, inorder, leftSize);
	// 右子树
	root->right = buildTree(preorder + 1 + leftSize, inorder + leftSize + 1, size - 1 - leftSize);
	return root;
}
void Test3() {
	char *preorder = "ABDEHCFG";	//前序
	char *inorder = "DBEHAFCG";		//中序
	int size = strlen(preorder);
	Node *root = buildTree(preorder, inorder, size);
}

// 2.中序 + 后序 还原树
int Find2(char array[], int size, char value) {			// 找后序根在中序的位置
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
	int leftSize = Find2(inorder, size, rootValue);			// 找后序根在中序的位置
	//根
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	//左子树
	root->left = buildTree2(inorder, postorder, leftSize);
	//右子树
	root->right = buildTree2(inorder + leftSize + 1, postorder + leftSize, size - 1 - leftSize);
	return root;
}



// 一、利用递归实现的前序/中序/后序		(深度优先遍历)		本质利用了系统调用栈		重点
// 二、利用队列实现二叉树的层序遍历		(广度优先遍历)
// 三、自己用栈实现前序/中序/后序		非递归方式										难点

#include <queue>
// 层序遍历
void LevelOrder(Node *root) {
	if (root == NULL) {
		printf("\n");
	}
	// 启动
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

// 判断二叉树是否是 完全二叉树
bool IsComplete(Node *root) {
	std::queue<Node *> q;
	q.push(root);
	while (true) {
		Node *front = q.front();
		q.pop();
		if (front == NULL) {
			break;
		}
		// 层序遍历，空结点也进队列
		q.push(front->left);
		q.push(front->right);
	}
	// 判定队列中剩余数据是否全是 NULL
	while (!q.empty()) {
		Node *front = q.front();
		q.pop();
		if (front != NULL) {
			return false;
		}
	}
	// 所有都是 NULL
	return true;
}
void Test5() {
	char *inorder = "DBEAC";
	char *postorder = "DEBCA";
	int size = strlen(inorder);
	Node *root = buildTree2(inorder, postorder, size);
	LevelOrder(root);
	if (IsComplete(root)) {
		printf("是完全二叉树\n");
	}
	else {
		printf("不是完全二叉树\n");
	}
}

// 非递归实现前序
// 递归缺点: 1.控制力度差 2.调整栈的大小比较麻烦(只能编译期间调整)
// 非递归 自定义的栈 + 循环
#include <stack>
// 非递归的二叉树写法(用栈写)
// 1.(前序遍历)
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
// 2.(中序遍历)
void InOrderNoR(Node *root) {
	std::stack<Node *> s;
	Node *cur = root;
	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}
		Node *top = s.top(); s.pop();
		printf("%c ", top->value);			// 把打印的语句加到这里就可以了
		cur = top->right;
	}
}
// 3.(后序遍历)
void PostOrderNoR(Node *root) {
	std::stack<Node *> s;
	Node *cur = root;
	Node *last = NULL;
	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			// 第一次遇到
			s.push(cur);
			cur = cur->left;
		}
		Node *top = s.top();
		// 我不知道是第二次遇到还是第三次遇到
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

// 最近公共祖先


// 二叉搜索树	红黑树	AVL树


// 二叉搜索树转成有序双向链表
Node *prev = NULL;
// 保证按有序的顺序调用该函数
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
		// 根 root
		NodeToDoublyLink(root);
		InOrder(root->right);
	}
}
