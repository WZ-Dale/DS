/*******************************链表********************************/
#include "LinkedList.h"
#include <stdlib.h>

void Test2(){
	LList llist;
	// 初始化 / 销毁
	LListInit(&llist);
	//尾插
	LListPushBack(&llist, 1);
	LListPushBack(&llist, 2);
	LListPushBack(&llist, 3);
	LListPushBack(&llist, 4);
	LListPushBack(&llist, 5);
	//头插
	LListPushFront(&llist, 10);
	LListPushFront(&llist, 20);
	LListPushFront(&llist, 30);
	LListPushFront(&llist, 40);
	LListPushFront(&llist, 50);
	//头删
	LListPopFront(&llist);
	//尾删
	LListPopBack(&llist);
	//翻转
	LListfanzhuan(&llist);

	//按值查找

	//按值删除
	

	//打印
	LListPrint(&llist);
}


int main() {
	Test2();

	system("pause");
	return 0;
}
