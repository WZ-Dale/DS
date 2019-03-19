#include "SequenceList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//O(n)
//static ���κ���������������,���ⲿ�������Ըı�Ϊ�ڲ���������
//1.������ݲ���ʱ,�Ƿ���Ҫ����,�����Ҫ,������
static void CheckCapacity(SeqList* seqlist){
	if (seqlist->size < seqlist->capacity){
		//����Ҫ����,����
		return;
	}
	else{
		//��Ҫ����
		//1.��������
		int newCapacity = 2 * seqlist->capacity;
		SLDataType* newArray = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));
		//2.copy �ɿռ�����ݵ��µĿռ�
		int i = 0;
		for (i = 0; i < seqlist->size; ++i){
			newArray[i] = seqlist->array[i];
		}
		//3.�ͷžɵĿռ�,�����µĿռ�󶨵�˳���ṹ��
		free(seqlist->array);
		seqlist->array = newArray;				//��ʵ����ָ���ڴ���ַ,�����¿ռ���׵�ַ�ŵ�seqlist->array
		//4.��������
		seqlist->capacity = newCapacity;
	}
}
//2.��ʼ��
void SeqListInit(SeqList* seqlist, int capacity){
	//�ڶ��Ϸ���˳���Ĵ洢�ռ�
	//��ʼ��������size�ֶ�
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	seqlist->array = (SLDataType*)malloc(capacity * sizeof(SLDataType));	//����ָ�����ȵĿռ�,���ѵ�ַ��seqlist->array
	seqlist->capacity = capacity;		//ָ������
	seqlist->size = 0;		//��ʼ����Ϊ0
}
//3.����
void SeqListDestory(SeqList* seqlist){
	//���ͷ�˳���Ĵ洢�ռ�
	//����Ĺ���,���ֶ�����Ϊ��ʼֵ
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	free(seqlist->array);		//�ͷſռ�
	//������
	seqlist->array = NULL;		//ָ���
	seqlist->capacity =	seqlist->size = 0;		//����
}
//4.β��
//ʱ�临�Ӷ�ΪO(1)
void SeqListPushBack(SeqList* seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	CheckCapacity(seqlist);			//����֮ǰҪ���ռ��Ƿ�����(�Ƿ���Ҫ����)
	seqlist->array[seqlist->size] = v;
	++seqlist->size;
}
//5.ͷ��
void SeqListPushFront(SeqList* seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	CheckCapacity(seqlist);
	int i = 0;			//�� i ��ʾ�±�
	for (i = seqlist->size; i > 0; --i){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = v;
	++seqlist->size;
}
//6.����pos�±����
void SeqListInsert(SeqList* seqlist, int pos, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos >= 0 && pos <= seqlist->size);
	CheckCapacity(seqlist);
	int i = 0;			//�� i ��ʾ�±�
	for (i = seqlist->size; i > pos; --i){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[pos] = v;
	++seqlist->size;
}
//7.βɾ
void SeqListPopBack(SeqList* seqlist){
	assert(seqlist != NULL);
	assert(seqlist->size > 0);
	--seqlist->size;
}
//8.ͷɾ
void SeqListPopFront(SeqList* seqlist){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	int i = 0;			//�� i ��ʾ�±�
	for (i = 0; i <= seqlist->size - 2; ++i){
		seqlist->array[i] = seqlist->array[i + 1];
	}
	--seqlist->size;
}
//9.����pos�±�ɾ��
void SeqListErase(SeqList* seqlist, int pos){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	assert(pos >= 0 && pos < seqlist->size);
	int i = 0;			//�� i ��ʾ�±�
	for (i = pos; i <= seqlist->size - 2; ++i){
		seqlist->array[i] = seqlist->array[i + 1];
	}
	--seqlist->size;
}
//10.��
void SeqListModify(SeqList* seqlist, int pos, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos >= 0 && pos < seqlist->size);
	seqlist->array[pos] = v;
}
//11.��
//�ҵ��Ļ����������ĵ�һ�� v ���±꣬û�ҵ��򷵻� -1
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
//12.��ӡ
void SeqListPrint(const SeqList* seqlist){
	int i = 0;
	for (i = 0; i < seqlist->size; ++i){
		printf("%d  ",seqlist->array[i]);
	}
	printf("\n");
}
//13.ɾ����һ��������v
void SeqListRemove(SeqList* seqlist, SLDataType v){
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	int pos = SeqListFind(seqlist, v);
	if (pos != -1){						//�˴�������ж�,���û���ҵ��򷵻�-1,-1�Ļ��Ͳ���Ҫɾ����
		SeqListErase(seqlist, pos);
	}
}
//14.ɾ�����������е�v
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
//15.ð������
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
//16.���ֲ���
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
