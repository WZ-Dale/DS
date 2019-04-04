/*******************************链表********************************/
#include "LinkedList.h"
#include <stdlib.h>

void Test2(){
	LList llist;
	// 初始化 / 销毁
	LListInit(&llist);
	//头插
	LListPushFront(&llist, 10);
	LListPushFront(&llist, 20);
	LListPushFront(&llist, 30);
	LListPushFront(&llist, 40);
	LListPushFront(&llist, 50);//50,40,30,20,10
	//尾插
	LListPushBack(&llist, 1);
	LListPushBack(&llist, 2);
	LListPushBack(&llist, 3);
	LListPushBack(&llist, 4);
	LListPushBack(&llist, 5);//50,40,30,20,10,1,2,3,4,5
	//头删
	LListPopFront(&llist);//40,30,20,10,1,2,3,4,5
	//尾删
	LListPopBack(&llist);//40,30,20,10,1,2,3,4
	//在pos后面插入
	//LListPosAfter(&llist, 地址, v);//输入地址在地址处插入
	//在pos后删
	//LListEraseAfter(&llist, 地址);
	//按值查找
	printf("查: %p\n", LListFind(&llist, 3));//输出地址
	//按值改
	LListModify(&llist, 1, 2);//40,30,20,10,2,2,3,4
	//按值删除第一个
	LListRemove(&llist, 3);//40,30,20,10,2,2,4
	//按值删除所有
	//LListRemoveAll(&llist, 2);//40,30,20,10,4
	//按值删除所有2
	LListRemoveAll2(&llist, 2);//40,30,20,10,4
	//链表翻转
	LListReverse(&llist); //4,10,20,30,40
	//打印
	LListPrint(&llist);
}


int main() {
	Test2();

	system("pause");
	return 0;
}
