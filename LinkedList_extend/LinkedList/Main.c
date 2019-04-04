/*******************************����********************************/
#include "LinkedList.h"
#include <stdlib.h>

void Test2(){
	LList llist;
	// ��ʼ�� / ����
	LListInit(&llist);
	//ͷ��
	LListPushFront(&llist, 10);
	LListPushFront(&llist, 20);
	LListPushFront(&llist, 30);
	LListPushFront(&llist, 40);
	LListPushFront(&llist, 50);//50,40,30,20,10
	//β��
	LListPushBack(&llist, 1);
	LListPushBack(&llist, 2);
	LListPushBack(&llist, 3);
	LListPushBack(&llist, 4);
	LListPushBack(&llist, 5);//50,40,30,20,10,1,2,3,4,5
	//ͷɾ
	LListPopFront(&llist);//40,30,20,10,1,2,3,4,5
	//βɾ
	LListPopBack(&llist);//40,30,20,10,1,2,3,4
	//��pos�������
	//LListPosAfter(&llist, ��ַ, v);//�����ַ�ڵ�ַ������
	//��pos��ɾ
	//LListEraseAfter(&llist, ��ַ);
	//��ֵ����
	printf("��: %p\n", LListFind(&llist, 3));//�����ַ
	//��ֵ��
	LListModify(&llist, 1, 2);//40,30,20,10,2,2,3,4
	//��ֵɾ����һ��
	LListRemove(&llist, 3);//40,30,20,10,2,2,4
	//��ֵɾ������
	//LListRemoveAll(&llist, 2);//40,30,20,10,4
	//��ֵɾ������2
	LListRemoveAll2(&llist, 2);//40,30,20,10,4
	//����ת
	LListReverse(&llist); //4,10,20,30,40
	//��ӡ
	LListPrint(&llist);
}


int main() {
	Test2();

	system("pause");
	return 0;
}
