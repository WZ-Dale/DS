#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1.��ʼ�� / ����
void LListInit(LList *llist) {
	llist->first = NULL;
}
//2.ͷ��
void LListPushFront(LList *llist, LLDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));	//�����½��
	node->value = v;
	node->next = llist->first;		//��������Ĺ�ϵ
	llist->first = node;			//���ǿ�����ͷǿ�������һ���Ĵ���
}
//3.β��
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
//4.ͷɾ
void LListPopFront(LList *llist) {
	assert(llist->first != NULL);		//�ų���������һ����㶼û�е����
	Node *save = llist->first->next;	//������һ����ַ
	free(llist->first);					//�ͷŵ�һ���ڵ�
	llist->first = save;				//������ͷָ�򱣴�ĵ�ַ
}
//5.βɾ
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
//6.��pos�������
void LListPosAfter(LList *llist, Node *pos, LLDataType v){
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}
//7.��pos��ɾ
LListEraseAfter(LList *llist, Node *pos){
	Node *save = pos->next->next;
	free(pos->next);
	pos->next = save;
}
//8.��ֵ����
Node *LListFind(LList *llist, LLDataType v){
	Node *p = llist->first;
	/*while (p != NULL){
		if (p->value == v){
			return p;
		}
		p = p->next;
	}*/
	for (p = llist->first; p != NULL; p = p->next){
		if (p->value == v){
			return p;
		}
	}
	return NULL;
}
//9.��ֵ��
void LListModify(LList *llist, LLDataType v, LLDataType m){
	if (llist->first == NULL){
		return;
	}
	Node *p = llist->first;
	while (p->next != NULL){
		if (p->value == v){
			p->value = m;
		}
		p = p->next;
	}
}
//10.��ֵɾ����һ��
void LListRemove(LList *llist, LLDataType v){
	if (llist->first == NULL){
		return;
	}
	Node *p = llist->first;
	if (p->value == v){		//�����һ���ڵ�Ϊv,��ͷɾ
		LListPopFront(llist);
	}
	else{
		while (p->next != NULL){
			if (p->next->value == v){
				Node *save = p->next;		//����һ����Ҫɾ���Ŀռ�ĵ�ַ
				p->next = p->next->next;	//��ɾ���ĺ�һ���ڵ���׵�ַ���ӵ�ǰ��
				free(save);			//�������free()�ͷ�ɾ���Ŀռ�,��ᵼ���ڴ�й©
				return;
			}
			p = p->next;
		}
	}
}
//11.��ֵɾ������
void LListRemoveAll(LList *llist, LLDataType v){
	if (llist->first == NULL){
		return;
	}
	Node *p = llist->first;
	while (p->next != NULL){
		if (p->next->value == v){
			Node *save = p->next;
			p->next = p->next->next;		//��Ϊ p �Ѿ��ı�,������ else
			free(save);
		}
		else{
			p = p->next;
		}
	}
	if (llist->first->value == v){			//������һ���ڵ��Ƿ���Ҫɾ��,�Ӷ����ⷴ�����ͷ���
		LListPopFront(llist);
	}
}
//12.����ת
void LListReverse(LList *llist) {
	Node *result = NULL;
	Node *p = llist->first;
	while(p != NULL ){
		Node *save = p->next;			//������һ�ڵ�ĵ�ַ
		p->next = result;				//�õ�ǰ�ڵ��һ��ָ�� NULL, �ٴν�����ָ���� p
		result = p;						//���浱ǰ�ڵ�ĵ�ַ
		p = save;						//p�д����һ�ڵ�ĵ�ַ
	}
	llist->first = result;				//��ת�ɹ���ͷ���ĵ�ַ�� llist->first
}
//13.��ӡ
void LListPrint(const LList* llist){
	Node *p = llist->first;
	while(p != NULL){
		printf("%d  ", p->value);
		p = p->next;
	}
	printf("\n");
}
