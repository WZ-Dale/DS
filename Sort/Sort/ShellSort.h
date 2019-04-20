#pragma once
#include <stdio.h>
#include "BasicSort.h"

// ��������(����)
void InsertSort3(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int save = array[i];			// ������Ҫ�������
		int j;
		for (j = i - 1; j >= 0; --j) {
			if (array[j] <= save) {
				break;
			}
			array[j + 1] = array[j];	// �ѱ�save�������Ų
		}
		array[j + 1] = save;			// ��save���뵽���ʵ�λ��
	}
}
// ϣ������ --- ���������������
// �������
void InsertSortWithGap(int array[], int size, int gap) {
	for (int i = 0; i < size; i++) {
		int save = array[i];
		int j;
		for (j = i - gap; j >= 0; j -= gap) {
			if (array[j] <= save) {
				break;
			}
			array[j + gap] = array[j];
		}
		array[j + gap] = save;
	}
}
void ShellSort(int array[], int size) {
	int gap = size;
	while (gap != 1) {			// ������ĳ���Ϊ1ʱ,���ź���
		gap = gap / 3 + 1;		// �����㷨
		InsertSortWithGap(array, size, gap);
	}
}
// ����
void Test1() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 6 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArray(array, size);
	ShellSort(array, size);
	PrintArray(array, size);
}