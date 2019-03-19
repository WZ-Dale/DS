#pragma once

//��̬˳���:˳���������ڱ����ڼ�(��̬�ڼ�)������,д���ڴ������
/*
typdef struct SeqList{
	int array[100];		//������100
	int size;
}SeqList;
*/

typedef int SLDataType;

//����˳���ṹ��
typedef struct SeqList{
	SLDataType* array;	//����һ��int*ָ��
	int capacity;		//����
	int size;
}SeqList;


//1.��ʼ��
//��ʼ����ʱ��size = 0
//size = -1		//���һ����Ч���ݵ��±�
void SeqlistInit(SeqList* seqlist, int capacity);

//2.����
void SeqListDestory(SeqList* seqlist);


//1.��
//β��
void SeqListPushBack(SeqList* seqlist, SLDataType v);
//ͷ��
void SeqListPushFront(SeqList* seqlist, SLDataType v);
//����pos�±����
void SeqListInsert(SeqList* seqlist, int pos, SLDataType v);

//2.ɾ
//βɾ
void SeqListPopBack(SeqList* seqlist);
//ͷɾ
void SeqListPopFront(SeqList* seqlist);
//����pos�±�ɾ��
void SeqListErase(SeqList* seqlist, int pos);

//3.��
//inline ��������
/*
static void SeqListModify(SeqList* seqlist, int pos, SLDataType v){
	seqlist->array[pos] = v;
}
*/
void SeqListModify(SeqList* seqlist, int pos, SLDataType v);

//4.��
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


//1.��ӡ
void SeqListPrint(const SeqList* seqlist);

//1.ɾ����һ��������v
void SeqListRemove(SeqList* seqlist, SLDataType v);
//2.ɾ�����������е�v
void SeqListRemoveAll(SeqList* seqlist, SLDataType v);

//1.ð������
void SeqListBubbleSort(SeqList* seqlist);
//2.���ֲ���
int SeqListBinaryFind(SeqList* seqlist, SLDataType v);
