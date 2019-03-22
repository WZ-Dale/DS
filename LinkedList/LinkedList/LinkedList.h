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
//ͷ��
void LListPushFront(LList *llist, LLDataType v);
//β��
void LListPushBack(LList *llist, LLDataType v);
//��pos�������
void LLisPosAfter(LList *llist, Node *pos, LLDataType v);

//2.ɾ
//ͷɾ
void LListPopFront(LList *llist);
//βɾ
void LListPopBack(LList *llist);
//��pos��ɾ
LListEraseAfter(LList *llist, Node *pos);
//��ֵɾ����һ��
void LListRemove(LList *llist, LLDataType v);
//��ֵɾ������
void LListRemoveAll(LList *llist, LLDataType v);

//3.��
//��ֵ��
void LListModify(LList *llist, LLDataType v, LLDataType m);

//4.��
//��ֵ����
Node *LListFind(LList *llist, LLDataType v);

//5.����ת
void LListReverse(LList *llist);
//6.��ӡ
void LListPrint(const LList* llist);
