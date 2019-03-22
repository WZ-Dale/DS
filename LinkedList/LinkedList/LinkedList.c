#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1.初始化 / 销毁
void LListInit(LList *llist) {
	llist->first = NULL;
}
//2.头插
void LListPushFront(LList *llist, LLDataType v) {
	Node *node = (Node *)malloc(sizeof(Node));	//申请新结点
	node->value = v;
	node->next = llist->first;		//更改链表的关系
	llist->first = node;			//考虑空链表和非空链表都是一样的处理
}
//3.尾插
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
//4.头删
void LListPopFront(LList *llist) {
	assert(llist->first != NULL);		//排除掉链表中一个结点都没有的情况
	Node *save = llist->first->next;	//保存下一跳地址
	free(llist->first);					//释放第一个节点
	llist->first = save;				//将链表头指向保存的地址
}
//5.尾删
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
//6.在pos后面插入
void LListPosAfter(LList *llist, Node *pos, LLDataType v){
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}
//7.在pos后删
LListEraseAfter(LList *llist, Node *pos){
	Node *save = pos->next->next;
	free(pos->next);
	pos->next = save;
}
//8.按值查找
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
//9.按值改
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
//10.按值删除第一个
void LListRemove(LList *llist, LLDataType v){
	if (llist->first == NULL){
		return;
	}
	Node *p = llist->first;
	if (p->value == v){		//如果第一个节点为v,则头删
		LListPopFront(llist);
	}
	else{
		while (p->next != NULL){
			if (p->next->value == v){
				Node *save = p->next;		//保存一下需要删除的空间的地址
				p->next = p->next->next;	//将删除的后一个节点的首地址链接到前面
				free(save);			//如果不用free()释放删除的空间,则会导致内存泄漏
				return;
			}
			p = p->next;
		}
	}
}
//11.按值删除所有
void LListRemoveAll(LList *llist, LLDataType v){
	if (llist->first == NULL){
		return;
	}
	Node *p = llist->first;
	while (p->next != NULL){
		if (p->next->value == v){
			Node *save = p->next;
			p->next = p->next->next;		//因为 p 已经改变,所以用 else
			free(save);
		}
		else{
			p = p->next;
		}
	}
	if (llist->first->value == v){			//最后检查第一个节点是否需要删除,从而避免反复检查头结点
		LListPopFront(llist);
	}
}
//12.链表翻转
void LListReverse(LList *llist) {
	Node *result = NULL;
	Node *p = llist->first;
	while(p != NULL ){
		Node *save = p->next;			//保存下一节点的地址
		p->next = result;				//让当前节点第一次指向 NULL, 再次进来就指向了 p
		result = p;						//保存当前节点的地址
		p = save;						//p中存放下一节点的地址
	}
	llist->first = result;				//翻转成功后将头结点的地址给 llist->first
}
//13.打印
void LListPrint(const LList* llist){
	Node *p = llist->first;
	while(p != NULL){
		printf("%d  ", p->value);
		p = p->next;
	}
	printf("\n");
}
