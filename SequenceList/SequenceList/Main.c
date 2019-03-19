/**************************顺序表**************************/
#include "SequenceList.h"
#include <stdlib.h>

void Test1(){
#if 1
	SeqList seqlist;		//定义一个SeqList类型的顺序表seqlist

	SeqListInit(&seqlist, 10);		//初始化这个顺序表seqlist,给定长度为10
	//尾插
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 3);
	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, 5);//1 2 3 4 5 
	//头插
	SeqListPushFront(&seqlist, 10);
	SeqListPushFront(&seqlist, 20);
	SeqListPushFront(&seqlist, 30);
	SeqListPushFront(&seqlist, 40);
	SeqListPushFront(&seqlist, 50);//50 40 30 20 10 1 2 3 4 5 
	//已经插满,再插入应该需要扩容
	//根据pos下标插入
	SeqListInsert(&seqlist, 5, 666);//50 40 30 20 10 666 1 2 3 4 5 
	//尾删
	SeqListPopBack(&seqlist);//50 40 30 20 10 666 1 2 3 4 
	//头删
	SeqListPopFront(&seqlist);//40 30 20 10 666 1 2 3 4 
	//根据pos下标删除
	SeqListErase(&seqlist, 2);//40 30 10 666 1 2 3 4 
	//改
	SeqListModify(&seqlist, 6, 2);//40 30 10 666 1 2 2 4 
	//查
	printf("查: %d\n", SeqListFind(&seqlist, 1));//4
	//删除第一遇到的v
	SeqListRemove(&seqlist, 1);//40 30 10 666 2 2 4 
	//删除遇到的所有的v
	SeqListRemoveAll(&seqlist, 2);//40 30 10 666 4 
	//冒泡排序
	SeqListBubbleSort(&seqlist);//4 10 30 40 666
	//二分查找
	printf("二分查: %d\n", SeqListBinaryFind(&seqlist, 4));//3
#endif
	SeqListPrint(&seqlist);
}


int main(){
	Test1();
	system("pause");
	return 0;
}
