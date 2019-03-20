#pragma once

typedef int LLDataType;

// �����е�һ�����
typedef struct Node {
	LLDataType value;	// ֵ
	struct Node *next;		// ��һ�����ĵ�ַ
} Node, *NodePointer;
// Single List
typedef struct LList {
	Node *first;	// *head;		��һ�����ĵ�ַ
} LList;

// ��ʼ�� / ����
void LListInit(LList *llist);

//1.��
//β��
void LListPushBack(LList *llist, LLDataType v);
//ͷ��
void LListPushFront(LList *llist, LLDataType v);
//

//2.ɾ
//ͷɾ
void LListPopFront(LList *llist);
//βɾ
void LListPopBack(LList *llist);
//��ֵɾ��
void LListRemove(LList *llist, LLDataType v);
//3.��

//4.��

//11.��ӡ
void LListPrint(const LList* llist);
