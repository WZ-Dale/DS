#pragma once

namespace Peixinchen {
	void Sort(int array[], int size);
}

// ���Ե�
Peixinchen::Sort();

// ָ��
using Peixinchen::Sort;

Sort();

// ���
using Peixinchen;

Sort();


// �ṹ��Ľ�����		��(class)
struct SeqList {
	// ��Ա����	Ҳ���� c ����ֶ�
	int array[100];
	int size;

	void PushBack(int v);	// ��Ա����/��Ա����
};

struct SeqList	seqList;		// ����	object	instance ʵ��
struct SeqList	*pSeqList;	// ��������ռ�

seqList.PushBack(100);
pSeqList->PushBack(100);

// ģ��		���ͱ��
struct SeqList < typename T > {
	// ��Ա����	Ҳ���� c ����ֶ�
	T array[100];
	int size;

	void PushBack(T v);	// ��Ա����/��Ա����
};

SeqList<int>	sli;
SeqList<float>	slf;
