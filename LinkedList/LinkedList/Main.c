/*******************************����********************************/
#include "LinkedList.h"
#include <stdlib.h>

void Test2(){
	LList llist;
	// ��ʼ�� / ����
	LListInit(&llist);
	//β��
	LListPushBack(&llist, 1);
	LListPushBack(&llist, 2);
	LListPushBack(&llist, 3);
	LListPushBack(&llist, 4);
	LListPushBack(&llist, 5);
	//ͷ��
	LListPushFront(&llist, 10);
	LListPushFront(&llist, 20);
	LListPushFront(&llist, 30);
	LListPushFront(&llist, 40);
	LListPushFront(&llist, 50);
	//ͷɾ
	LListPopFront(&llist);
	//βɾ
	LListPopBack(&llist);
	//��ת
	LListfanzhuan(&llist);

	//��ֵ����

	//��ֵɾ��
	

	//��ӡ
	LListPrint(&llist);
}


int main() {
	Test2();

	system("pause");
	return 0;
}
