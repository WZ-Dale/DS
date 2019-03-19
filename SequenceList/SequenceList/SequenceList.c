#include "SequenceList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//O(n)
//static 修饰函数更改连接属性,从外部链接属性改变为内部链接属性
//1.检查数据插入时,是否需要扩容,如果需要,则扩容
static void CheckCapacity(SeqList* seqlist){
	if (seqlist->size < seqlist->capacity){
		//不需要扩容,结束
		return;
	}
	else{
		//需要扩容
		//1.进行扩容
		int newCapacity = 2 * seqlist->capacity;
		SLDataType* newArray = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));
		//2.copy 旧空间的数据到新的空间
		int i = 0;
		for (i = 0; i < seqlist->size; ++i){
			newArray[i] = seqlist->array[i];
		}
		//3.释放旧的空间,并把新的空间绑定到顺序表结构体
		free(seqlist->array);
		seqlist->array = newArray;				//其实这是指针在传地址,即把新空间的首地址放到seqlist->array
		//4.更新容量
		seqlist->capacity = newCapacity;
	}
}
//2.初始化
void SeqListInit(SeqList* seqlist, int capacity){
	//在堆上分配顺序表的存储空间
	//初始化容量和size字段
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	seqlist->array = (SLDataType*)malloc(capacity * sizeof(SLDataType));	//开辟指定长度的空间,并把地址给seqlist->array
	seqlist->capacity = capacity;		//指定容量
	seqlist->size = 0;		//初始长度为0
}
//3.销毁
void SeqListDestory(SeqList* seqlist){
	//在释放顺序表的存储空间
	//额外的工作,把字段重置为初始值
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	free(seqlist->array);		//释放空间
	//锦上添花
	seqlist->array = NULL;		//指向空
	seqlist->capacity =	seqlist->size = 0;		//置零
}
//4.尾插
//时间复杂度为O(1)
void SeqListPushBack(SeqList* seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	CheckCapacity(seqlist);			//插入之前要检查空间是否已满(是否需要扩容)
	seqlist->array[seqlist->size] = v;
	++seqlist->size;
}
//5.头插
void SeqListPushFront(SeqList* seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	CheckCapacity(seqlist);
	int i = 0;			//用 i 表示下标
	for (i = seqlist->size; i > 0; --i){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = v;
	++seqlist->size;
}
//6.根据pos下标插入
void SeqListInsert(SeqList* seqlist, int pos, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos >= 0 && pos <= seqlist->size);
	CheckCapacity(seqlist);
	int i = 0;			//用 i 表示下标
	for (i = seqlist->size; i > pos; --i){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[pos] = v;
	++seqlist->size;
}
//7.尾删
void SeqListPopBack(SeqList* seqlist){
	assert(seqlist != NULL);
	assert(seqlist->size > 0);
	--seqlist->size;
}
//8.头删
void SeqListPopFront(SeqList* seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	int i = 0;			//用 i 表示下标
	for (i = 0; i <= seqlist->size - 2; ++i){
		seqlist->array[i] = seqlist->array[i + 1];
	}
	--seqlist->size;
}
//9.根据pos下标删除
void SeqListErase(SeqList* seqlist, int pos){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	assert(pos >= 0 && pos < seqlist->size);
	int i = 0;			//用 i 表示下标
	for (i = pos; i <= seqlist->size - 2; ++i){
		seqlist->array[i] = seqlist->array[i + 1];
	}
	--seqlist->size;
}
//10.改
void SeqListModify(SeqList* seqlist, int pos, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos >= 0 && pos < seqlist->size);
	seqlist->array[pos] = v;
}
//11.查
//找到的话返回遇到的第一个 v 的下标，没找到则返回 -1
int SeqListFind(const SeqList* seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	for (int i = 0; i < seqlist->size; i++) {
		if (seqlist->array[i] == v) {
			return i;
		}
	}
	return -1;
}
//12.打印
void SeqListPrint(const SeqList* seqlist){
	int i = 0;
	for (i = 0; i < seqlist->size; ++i){
		printf("%d  ",seqlist->array[i]);
	}
	printf("\n");
}
//13.删除第一次遇到的v
void SeqListRemove(SeqList* seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	int pos = SeqListFind(seqlist, v);
	if (pos != -1){						//此处需进行判断,如果没有找到则返回-1,-1的话就不需要删除了
		SeqListErase(seqlist, pos);
	}
}
//14.删除遇到的所有的v
void SeqListRemoveAll(SeqList* seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	int pos = 0;
	for (pos = 0; pos < seqlist->size; ++pos){
		int pos = SeqListFind(seqlist, v);
		if (pos != -1){
			SeqListErase(seqlist, pos);
		}
	}
}
//15.冒泡排序
void SeqListBubbleSort(SeqList* seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	int i = 0, j = 0;
	for (i = 0; i < seqlist->size - 1; ++i){
		for (j = i+1; j < seqlist->size; ++j){
			if (seqlist->array[i] > seqlist->array[j]){
				SLDataType tmp;
				tmp = seqlist->array[i];
				seqlist->array[i] = seqlist->array[j];
				seqlist->array[j] = tmp;
			}
		}
	}
}
//16.二分查找
int SeqListBinaryFind(SeqList* seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	int left = 0, mid = 0, right = seqlist->size - 1;
	while(left <= right){
		mid = (left + right) / 2;
		if (seqlist->array[mid] == v){
			return mid;
		}
		else if (seqlist->array[mid] > v){
			right = mid - 1;
		}
		else if (seqlist->array[mid] < v){
			left = mid + 1;
		}
	}
	return -1;
}
