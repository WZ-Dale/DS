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
		if (p->next->value == v){			//�������ֵΪv��������һ��
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
//11.1��ֵɾ������2
void LListRemoveAll2(LList *llist, LLDataType v){
	Node *result = NULL;	//�������ĵ�һ���ڵ�
	Node *last = NULL;		//�����������һ���ڵ�
	Node *p = llist->first;
	while(p != NULL){
		if (p->value != v){				//�������������еĽڵ�,�������ֵ����v,�Ͱ�������β�嵽һ�����������
			if (last == NULL){
				result = p;				//����������ͷ��result
				last = p;				//Ϊͷ����p
			}
			else{
				last->next = p;			//Ϊlast����p
				last = p;				//�������һ���ڵ�
			}
		}
		p = p->next;
	}
	if (last != NULL){				//���������Ϊ�յĻ�,last���������Ϊ��
		last->next = NULL;
	}	
	llist->first = result;
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


/****************************��չ*****************************/
//������������ϲ���һ����������
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
			//β��
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
			//β��
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
	//l1����l2������һ��ΪNULL,������һ���Ľڵ㱻ȡ����
	if (l1 != NULL){
		last->next = l1;
	}
	if (l2 != NULL){
		last->next = l2;
	}
	return result;
}
//��xС�ķ�ǰ��,��x��ķź��
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
	if (small_last != NULL){	//�����xС�������н��,����������������
		small_last->next = big;
	}
	if (big_last != NULL){		//�����x��������н��,�����һ������next = NULL
		big_last->next = NULL;
	}
	if (small_last != NULL){	//��С��,��С�ķ���
		return small;
	}
	else{						//����Ӵ�ķ���
		return big;
	}
	//ע��:
	//��Ҫ���Ǳ�xС���߱�x���������Ϊ����������
	//һ��Ҫ��֤���շ�����������һ������next == NULL
}

//�����˫ָ�������------------����ָ��
//���������м���
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
//�ҵ�����k�����
struct Node *LListFindKthToTail(LList *llist, unsigned int k){
	Node *front = llist;
	Node *back = llist;
	//��ǰ�������k��
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
//ɾ�������������ظ������н��	��1,2,3,3,4,4,5	ɾ��Ϊ1,2,5
struct Node *LListDeleteDuplication(struct Node *pHead){
	if (pHead == NULL){
		return NULL;
	}
	Node *fake = (Node *)malloc(sizeof(Node));		//�ٽ��
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
			//û��free���,���ڴ�й©
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
//�ж������Ƿ��ǻ���
//1.�ҵ��м���	2.���ú�һ��	3.��head��rhead�Ƚ�



//������,�ҵ��������ʼ���



//�ж������Ƿ����



//��������ֶ�random,randomָ��������
//1.�ȸ���next��value: ���½ڵ�����Ͻ�����	2.�ٸ���random	3.�ٰ�����������
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
	//1.�ȸ���next��value: ���½ڵ�����Ͻ�����
	RNode *p = head;
	while (p != NULL){
		RNode *newNode = (RNode *)malloc(sizeof(RNode));
		newNode->value = oldNode->value;
		newNode->next = oldNode->next;
		oldNode->next = newNode;
		p = p->next;
	}
	//2.�ٸ���random
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
	//3.�ٰ�����������


}


//��������	Single List


//˫������	Double List









