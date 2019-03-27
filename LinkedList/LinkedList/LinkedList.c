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
		if (p->next->value == v){			//如果发现值为v则续接下一个
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
//11.1按值删除所有2
void LListRemoveAll2(LList *llist, LLDataType v){
	Node *result = NULL;	//结果链表的第一个节点
	Node *last = NULL;		//结果链表的最后一个节点
	Node *p = llist->first;
	while(p != NULL){
		if (p->value != v){				//遍历整个链表中的节点,如果发现值不是v,就把这个结点尾插到一个结果链表上
			if (last == NULL){
				result = p;				//将结果链表的头给result
				last = p;				//为头续接p
			}
			else{
				last->next = p;			//为last续接p
				last = p;				//更新最后一个节点
			}
		}
		p = p->next;
	}
	if (last != NULL){				//如果链表彻底为空的话,last做到最后还是为空
		last->next = NULL;
	}	
	llist->first = result;
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


/****************************扩展*****************************/
//两个有序链表合并成一个有序链表
struct Node *LListMergeTwoLists(struct Node *llist1, struct Node *llist2){
	struct Node *l1 = llist1;
	struct Node *l2 = llist2;
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
	}
	Node *result = NULL;
	Node *last = NULL;
	while (l1 != NULL && l2 != NULL){
		if (l1->value <= l2->value){
			//尾插
			if (result == NULL){
				result = last = l1;
			}
			else{
				last->next = l1;
				last = l1;
			}
			l1 = l1->next;
		}
		else{
			//尾插
			if (result == NULL){
				result = last = l2;
			}
			else{
				last->next = l2;
				last = l2;
			}
			l2 = l2->next;
		}
	}
	//l1或者l2其中有一个为NULL,即其中一个的节点被取完了
	if (l1 != NULL){
		last->next = l1;
	}
	if (l2 != NULL){
		last->next = l2;
	}
	return result;
}
//比x小的放前边,比x大的放后边
struct Node *LListSmallxBig(LList *llist, LLDataType x){
	Node *small = NULL;
	Node *small_last = NULL;
	Node *big = NULL;
	Node *big_last = NULL;
	Node *p = llist->first;
	while (p != NULL){
		if (p->value < x){
			if (small == NULL){
				small = small_last = p;
			}
			else{
				small_last->next = p;
				small_last = p;
			}
		}
		else{
			if (big == NULL){
				big = big_last = p;
			}
			else{
				big_last->next = p;
				big_last = p;
			}
		}
		p = p->next;
	}
	if (small_last != NULL){	//如果比x小的链表有结点,则把两个链表接起来
		small_last->next = big;
	}
	if (big_last != NULL){		//如果比x大的链表有结点,则最后一个结点的next = NULL
		big_last->next = NULL;
	}
	if (small_last != NULL){	//有小的,从小的返回
		return small;
	}
	else{						//否则从大的返回
		return big;
	}
	//注意:
	//需要考虑比x小或者比x大的链表有为空链表的情况
	//一定要保证最终返回链表的最后一个结点的next == NULL
}

//链表的双指针遍历法------------快慢指针
//返回链表中间结点
struct Node *LListMiddleNode(LList *llist){
	struct Node *fast = llist->first;
	Node * slow = llist->first;
	while (fast != NULL){
		fast = fast->next;
		if (fast == NULL){
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
//找倒数第k个结点
struct Node *LListFindKthToTail(LList *llist, unsigned int k){
	Node *front = llist;
	Node *back = llist;
	//让前面的先走k步
	int i = 0;
	for ( ; i < k && front != NULL; ++i){
		front = front->next;
	}
	if (i < k){
		return NULL;
	}
	while (front != NULL){
		front = front->next;
		back = back->next;
	}
	return back;
}
//删除有序链表中重复的所有结点	如1,2,3,3,4,4,5	删完为1,2,5
struct Node *LListDeleteDuplication(struct Node *pHead){
	if (pHead == NULL){
		return NULL;
	}
	Node *fake = (Node *)malloc(sizeof(Node));		//假结点
	fake->next = pHead;
	Node *prev = fake;
	Node *p1 = pHead;
	Node *p2 = pHead->next;
	while(p2 != NULL){
		if (p1->value != p2->value){
			prev = p1; p1 = p2; p2 = p2->next;
		}
		else{
			while (p2 != NULL && p2->next == p1->value){
				p2 = p2->next;
			}
			//没有free结点,有内存泄漏
			Node *cur = p1;
			while (cur != p2){
				Node *next = cur->next;
				free(cur);
				cur = next;
			}
			prev->next = p2;

			p1 = p2;
			if (p2 != NULL){
				p2 = p2->next;
			}
		}
	}
	pHead = fake->next;
	free(fake);
	return pHead;
}
//判断链表是否是回文
//1.找到中间结点	2.逆置后一半	3.拿head和rhead比较



//链表交叉,找到交叉的起始结点



//判断链表是否带环



//结点增加字段random,random指向任意结点
//1.先复制next和value: 让新节点跟在老结点后面	2.再复制random	3.再把链表拆成两个
typedef struct RNode{
	int value;
	struct RNode *random;
	struct RNode *next;
}RNode;


struct RNode *LListAddRandomCopy(struct Node *head){
	RNode *oldNode = head;
	if (head = NULL){
		return head;
	}
	//1.先复制next和value: 让新节点跟在老结点后面
	RNode *p = head;
	while (p != NULL){
		RNode *newNode = (RNode *)malloc(sizeof(RNode));
		newNode->value = oldNode->value;
		newNode->next = oldNode->next;
		oldNode->next = newNode;
		p = p->next;
	}
	//2.再复制random
	p = head;
	while (p != NULL){
		RNode *newNode = oldNode->next;
		if (oldNode->random == NULL){
			newNode->random == NULL;
		}
		else{
			newNode->random = oldNode->random->next;
		}
		p = p->next;
	}
	//3.再把链表拆成两个


}


//单向链表	Single List


//双向链表	Double List









