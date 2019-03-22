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
//头插
void LListPushFront(LList *llist, LLDataType v);
//尾插
void LListPushBack(LList *llist, LLDataType v);
//在pos后面插入
void LLisPosAfter(LList *llist, Node *pos, LLDataType v);

//2.删
//头删
void LListPopFront(LList *llist);
//尾删
void LListPopBack(LList *llist);
//在pos后删
LListEraseAfter(LList *llist, Node *pos);
//按值删除第一个
void LListRemove(LList *llist, LLDataType v);
//按值删除所有
void LListRemoveAll(LList *llist, LLDataType v);

//3.改
//按值改
void LListModify(LList *llist, LLDataType v, LLDataType m);

//4.查
//按值查找
Node *LListFind(LList *llist, LLDataType v);

//5.链表翻转
void LListReverse(LList *llist);
//6.打印
void LListPrint(const LList* llist);
