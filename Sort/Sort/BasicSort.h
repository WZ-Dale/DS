#pragma once
#include <stdio.h>

void Swap(int array[], int a, int b){
	int t = array[a];
	array[a] = array[b];
	array[b] = t;
}
void PrintArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

// ð������ --- ����ŵ�����,������ԭ��,�����������������(�д�ľͽ���������ð��)
void BubbleSort(int array[], int size){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size - 1 - i; ++j){
			if (array[j] > array[j + 1]){
				Swap(array, j, j + 1);		// ÿ�αȽϳɹ���,�����н���
			}
			//PrintArray(array, size);		// �鿴ð�ݹ���
		}
		//printf("\n");						// �鿴ð�ݹ���
	}
}
// ѡ������ --- ����ŵ�ǰ��,��ʱ������¼��������С�����±�,����ֵ�������е�һ��������(��С�ļ�¼��,���꽻��)
void SelectSort(int array[], int size){
	for (int i = 0; i < size - 1; ++i){
		int save = i;						// ��ʱ����,���ڼ�¼�±�
		for (int j = i + 1; j < size; ++j){
			if (array[j] < array[save]){
				save = j;					// ��¼�ȽϺ��С�����±�
			}
			//printf("[%d]=%d  ", save, array[save]), PrintArray(array, size);	// �鿴ѡ�����
		}									// �����бȽ����,save����ľ�����������С�����±�
		Swap(array, i, save);				// ����ֵ�������е�һ��������
		//printf("[%d]=%d  ", save, array[save]), PrintArray(array, size);	// �鿴ѡ�����
		//printf("\n");						// �鿴ѡ�����
	}
}
// �������� --- ����ŵ�ǰ��,�������е�һ�����������е����Ƚϴ�С,�ҵ�����λ�ò���
void InsertSort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		int save = array[i];				// ������Ҫ�������
		int j;
		for (j = i - 1; j >= 0; --j) {
			if (array[j] < save) {
				break;
			}
			array[j + 1] = array[j];		// �ѱ�save�������Ų
			printf("save=%d  ", save), PrintArray(array, size);	// �鿴�������
		}
		array[j + 1] = save;				// ��save���뵽���ʵ�λ��
		printf("save=%d  ", save), PrintArray(array, size);	// �鿴�������
		printf("\n");
	}
}

// ����
void Test() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 6};
	int size = sizeof(array) / sizeof(array[0]);
	printf("����ǰ���飺\n");
	PrintArray(array, size);
	printf("\n������̣�\n");

	//BubbleSort(array, size);
	//SelectSort(array, size);
	InsertSort(array, size);

	printf("��������飺\n");
	PrintArray(array, size);
}