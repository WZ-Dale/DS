#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>


//1.初始化 / 销毁
void LListInit(LList *llist) {
	llist->first = NULL;
}
//2.尾插
void LListPushBack(LList *llist, LLDataType v){
	Node *node = (Node *)malloc(sizeof(Node));		//申请新节点
	node->value = v;
	node->next = NULL;
	if (llist->first == NULL){
		llist->first = node;
	}
	else{
		Node *p = llist->first;
		while (p->next != NULL){		//找原来链表的最后一个结点
			p = p->next;
		}
		p->next = node;
	}
}
//3.头插
void LListPushFront(LList *llist, LLDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));	//申请新结点
	node->value = v;
	node->next = llist->first;		//更改链表的关系
	llist->first = node;			//考虑空链表和非空链表都是一样的处理
}
//5.头删
void LListPopFront(LList *llist) {
	assert(llist->first != NULL);		//排除掉链表中一个结点都没有的情况
	Node *save = llist->first->next;	//保存下一跳地址
	free(llist->first);					//释放第一个节点
	llist->first = save;				//将链表头指向保存的地址
}
//6.尾删
void LListPopBack(LList *llist) {
	assert(llist->first != NULL);		//排除掉链表中一个结点都没有的情况
	if (llist->first->next == NULL){	//只有一个结点
		free(llist->first);				//释放该节点
		llist->first = NULL;			//将链表头指向空
		return;
	}
	else{
		Node *p = llist->first;
		while (p->next->next != NULL){	//找倒数第二个结点
			p = p->next;
		}
		free(p->next);				//p指向倒数第二个节点,则p->next指向最后一个节点
		p->next = NULL;
	}
}
//7.按值删除第一个
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
//7.按值删除所有
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
	if (llist->first->value == v){			//最后检查第一个
		LListPopFront(&llist);
	}
}
//8.链表翻转
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

//12.打印
void LListPrint(const LList* llist){
	Node *p = llist->first;
	while(p != NULL){
		printf("%d  ", p->value);
		p = p->next;
	}
	printf("\n");
}
