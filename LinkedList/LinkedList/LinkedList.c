#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>


//1.��ʼ�� / ����
void LListInit(LList *llist) {
	llist->first = NULL;
}
//2.β��
void LListPushBack(LList *llist, LLDataType v){
	Node *node = (Node *)malloc(sizeof(Node));		//�����½ڵ�
	node->value = v;
	node->next = NULL;
	if (llist->first == NULL){
		llist->first = node;
	}
	else{
		Node *p = llist->first;
		while (p->next != NULL){		//��ԭ����������һ�����
			p = p->next;
		}
		p->next = node;
	}
}
//3.ͷ��
void LListPushFront(LList *llist, LLDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));	//�����½��
	node->value = v;
	node->next = llist->first;		//��������Ĺ�ϵ
	llist->first = node;			//���ǿ�����ͷǿ�������һ���Ĵ���
}
//5.ͷɾ
void LListPopFront(LList *llist) {
	assert(llist->first != NULL);		//�ų���������һ����㶼û�е����
	Node *save = llist->first->next;	//������һ����ַ
	free(llist->first);					//�ͷŵ�һ���ڵ�
	llist->first = save;				//������ͷָ�򱣴�ĵ�ַ
}
//6.βɾ
void LListPopBack(LList *llist) {
	assert(llist->first != NULL);		//�ų���������һ����㶼û�е����
	if (llist->first->next == NULL){	//ֻ��һ�����
		free(llist->first);				//�ͷŸýڵ�
		llist->first = NULL;			//������ͷָ���
		return;
	}
	else{
		Node *p = llist->first;
		while (p->next->next != NULL){	//�ҵ����ڶ������
			p = p->next;
		}
		free(p->next);				//pָ�����ڶ����ڵ�,��p->nextָ�����һ���ڵ�
		p->next = NULL;
	}
}
//7.��ֵɾ����һ��
void LListRemove(LList *llist, LLDataType v){
	if (llist->first == NULL){
		return;
	}
	Node *p = llist->first;
	if (p->value == v){
		LListPopFront(&llist);
	}
	else{
		while (p->next != NULL){
			if (p->next->next == v){
				Node *save = p->next;
				p->next = p->next->next;
				free(save);
				return;
			}
			p = p->next;
		}
	}
}
//7.��ֵɾ������
void LListRemoveAll(LList *llist, LLDataType v){
	if (llist->first == NULL){
		return;
	}
	Node *p = llist->first;
	while (p->next != NULL){
		if (p->next->next == v){
			Node *save = p->next;
			p->next = p->next->next;
			free(save);
		}
		else{
			p = p->next;
		}
	}
	if (llist->first->value == v){			//������һ��
		LListPopFront(&llist);
	}
}
//8.����ת
Node *LListfanzhuan(LList *llist) {
	Node *result = NULL;
	Node *c = llist->first;
	while(c != NULL ){
		Node *p = c->next;
		c->next = result;
		result = c;
		c = p;
	}
	llist->first = result;
	return llist->first;
}

//12.��ӡ
void LListPrint(const LList* llist){
	Node *p = llist->first;
	while(p != NULL){
		printf("%d  ", p->value);
		p = p->next;
	}
	printf("\n");
}
