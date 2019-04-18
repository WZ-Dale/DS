#pragma once
#include <stdio.h>

void Swap(int array[], int a, int b){
	int t = array[a];
	array[a] = array[b];
	array[b] = t;
}
// ð������ --- ����ŵ�����,������ԭ��,�����������������(�д�ľͽ���)
void BubbleSort(int array[], int size){
	int i, j;
	for (i = 0; i < size - 1; ++i){
		for (j = i + 1; j < size; ++j){
			if (array[i] > array[j]){
				Swap(array, i, j);		// ÿ�αȽϳɹ���,�����н���
			}
		}
	}
}
// ѡ������ --- ����ŵ�����,С������¼�±�λ��,���Ƚ��������(���ļ�¼��,�����)
void SelectSort(int array[], int size){
	int i, j;
	for (i = 0; i < size; ++i){
		int save = 0;					// ��һ��С����,���ڼ�¼С��
		for (j = 0; j < size - i; ++j){
			if (array[j] > array[save]){
				save = j;				// ��¼�ȽϺ�ϴ���±�
			}
		}								// �Ƚ����,save����ľ��������±�
		Swap(array, save, size - 1 - i);
	}
}
// ��������(�����) --- ����ŵ�ǰ��,�������е����������е����Ƚϴ�С,�ҵ�����λ�ò���
void InsertSort(int array[], int size) {
	int i;
	for (i = 1; i < size; ++i){
		int save = array[i];			// ������Ҫ�������
		while (i > 0 && array[i - 1] > save){
			array[i] = array[i - 1];	// �ѱ�save�������Ų
			--i;
		}
		array[i] = save;				// ��save���뵽���ʵ�λ��
	}
}
// ��������(����)
void InsertSort2(int array[], int size) {
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
void PrintArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
// ����
void Test() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 6};
	int size = sizeof(array) / sizeof(array[0]);
	PrintArray(array, size);
	//BubbleSort(array, size);
	//SelectSort(array, size);
	//InsertSort(array, size);
	InsertSort2(array, size);
	PrintArray(array, size);
}