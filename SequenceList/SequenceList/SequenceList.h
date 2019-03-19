#pragma once

//静态顺序表:顺序表的容量在编译期间(静态期间)决定的,写死在代码里的
/*
typdef struct SeqList{
	int array[100];		//容量是100
	int size;
}SeqList;
*/

typedef int SLDataType;

//定义顺序表结构体
typedef struct SeqList{
	SLDataType* array;	//定义一个int*指针
	int capacity;		//容量
	int size;
}SeqList;


//1.初始化
//初始化的时候size = 0
//size = -1		//最后一个有效数据的下标
void SeqlistInit(SeqList* seqlist, int capacity);

//2.销毁
void SeqListDestory(SeqList* seqlist);


//1.增
//尾插
void SeqListPushBack(SeqList* seqlist, SLDataType v);
//头插
void SeqListPushFront(SeqList* seqlist, SLDataType v);
//根据pos下标插入
void SeqListInsert(SeqList* seqlist, int pos, SLDataType v);

//2.删
//尾删
void SeqListPopBack(SeqList* seqlist);
//头删
void SeqListPopFront(SeqList* seqlist);
//根据pos下标删除
void SeqListErase(SeqList* seqlist, int pos);

//3.改
//inline 内联函数
/*
static void SeqListModify(SeqList* seqlist, int pos, SLDataType v){
	seqlist->array[pos] = v;
}
*/
void SeqListModify(SeqList* seqlist, int pos, SLDataType v);

//4.查
/*
static int SeqListFind(const SeqList* seqlist, SLDataType v){
	for (int i = 0; i < seqlist->size; i++) {
		if (seqlist->array[i] == v) {
			return i;
		}
	}

	return -1;
}
*/
int SeqListFind(const SeqList* seqlist, SLDataType v);


//1.打印
void SeqListPrint(const SeqList* seqlist);

//1.删除第一次遇到的v
void SeqListRemove(SeqList* seqlist, SLDataType v);
//2.删除遇到的所有的v
void SeqListRemoveAll(SeqList* seqlist, SLDataType v);

//1.冒泡排序
void SeqListBubbleSort(SeqList* seqlist);
//2.二分查找
int SeqListBinaryFind(SeqList* seqlist, SLDataType v);
