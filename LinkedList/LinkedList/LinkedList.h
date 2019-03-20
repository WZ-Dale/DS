#pragma once

typedef int LLDataType;

// 链表中的一个结点
typedef struct Node {
	LLDataType value;	// 值
	struct Node *next;		// 下一个结点的地址
} Node, *NodePointer;
// Single List
typedef struct LList {
	Node *first;	// *head;		第一个结点的地址
} LList;

// 初始化 / 销毁
void LListInit(LList *llist);

//1.增
//尾插
void LListPushBack(LList *llist, LLDataType v);
//头插
void LListPushFront(LList *llist, LLDataType v);
//

//2.删
//头删
void LListPopFront(LList *llist);
//尾删
void LListPopBack(LList *llist);
//按值删除
void LListRemove(LList *llist, LLDataType v);
//3.改

//4.查

//11.打印
void LListPrint(const LList* llist);
