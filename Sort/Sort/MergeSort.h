#pragma once
#include <stdio.h>
#include "BasicSort.h"

// �鲢����
// �ⲿ����	��ѡ
void Merge(int array[], int left, int mid, int right, int extra[]) {// �鲢������������
	int i = left;	// ���������±�
	int j = mid;	// �ұ�������±�
	int k = left;	// extra ���±�

	while (i < mid && j < right) {
		if (array[i] <= array[j]) {
			extra[k++] = array[i++];
		}
		else {
			extra[k++] = array[j++];
		}
	}

	while (i < mid) {
		extra[k++] = array[i++];
	}

	while (j < right) {
		extra[k++] = array[j++];
	}

	// �� extra �������ƻ���
	for (int x = left; x < right; x++) {
		array[x] = extra[x];
	}
}
// [left, right)
void __MergeSort(int array[], int left, int right, int extra[]) {
	// ֱ��
	// size == 1	[3, 4)
	if (right == left + 1) {
		return;
	}
	// size == 0
	if (right <= left) {
		return;
	}

	// 1. ������ƽ���ֳ�������
	int mid = left + (right - left) / 2;
	// [left, mid)
	// [mid, right)
	// 2. �����㷨����������������
	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);

	// 3. �ϲ�������������
	// [left, mid)	[mid, right)
	Merge(array, left, mid, right, extra);
}
void MergeSort(int array[], int size) {
	int *extra = (int *)malloc(sizeof(int)* size);
	__MergeSort(array, 0, size, extra);
	free(extra);
}

// �ǵݹ�ʵ�ֹ鲢����
void MergeSortNoR(int array[], int size){
	








}

void Test3() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 10, 9 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	MergeSort(array, size);
	PrintArray(array, size);
}