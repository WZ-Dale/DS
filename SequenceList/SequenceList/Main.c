/**************************˳���**************************/
#include "SequenceList.h"
#include <stdlib.h>

void Test1(){
#if 1
	SeqList seqlist;		//����һ��SeqList���͵�˳���seqlist

	SeqListInit(&seqlist, 10);		//��ʼ�����˳���seqlist,��������Ϊ10
	//β��
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 3);
	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, 5);//1 2 3 4 5 
	//ͷ��
	SeqListPushFront(&seqlist, 10);
	SeqListPushFront(&seqlist, 20);
	SeqListPushFront(&seqlist, 30);
	SeqListPushFront(&seqlist, 40);
	SeqListPushFront(&seqlist, 50);//50 40 30 20 10 1 2 3 4 5 
	//�Ѿ�����,�ٲ���Ӧ����Ҫ����
	//����pos�±����
	SeqListInsert(&seqlist, 5, 666);//50 40 30 20 10 666 1 2 3 4 5 
	//βɾ
	SeqListPopBack(&seqlist);//50 40 30 20 10 666 1 2 3 4 
	//ͷɾ
	SeqListPopFront(&seqlist);//40 30 20 10 666 1 2 3 4 
	//����pos�±�ɾ��
	SeqListErase(&seqlist, 2);//40 30 10 666 1 2 3 4 
	//��
	SeqListModify(&seqlist, 6, 2);//40 30 10 666 1 2 2 4 
	//��
	printf("��: %d\n", SeqListFind(&seqlist, 1));//4
	//ɾ����һ������v
	SeqListRemove(&seqlist, 1);//40 30 10 666 2 2 4 
	//ɾ�����������е�v
	SeqListRemoveAll(&seqlist, 2);//40 30 10 666 4 
	//ð������
	SeqListBubbleSort(&seqlist);//4 10 30 40 666
	//���ֲ���
	printf("���ֲ�: %d\n", SeqListBinaryFind(&seqlist, 4));//3
#endif
	SeqListPrint(&seqlist);
}


int main(){
	Test1();
	system("pause");
	return 0;
}
