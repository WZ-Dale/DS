#pragma once
#include <stdio.h>

/*
������
O(n * log(n))		������
�ռ临�Ӷ�			O(1)
�ȶ��ԣ����ȶ�


���µ���

0. �������Ҷ�ӣ�����ͣ��
1. ���Һ�����ֵ�Ƚϴ��һ��
1) û���Һ���		����
2) ���Һ���
i. ���Ӵ�		����
ii. �Һ��Ӵ�	�Һ���
2. ���ӵ�ֵ�͸���ֵ���бȽ�
3. �������ֵ >= ���ӵ�ֵ�ˣ�����ͣ
4. �������������µ���
*/
void Heapify(int array[], int size, int rIdx) {
	while (1) {
		int leftIdx = 2 * rIdx + 1;
		int rightIdx = 2 * rIdx + 2;
		if (leftIdx >= size) {
			return;
		}

		int maxIdx;
		if (rightIdx >= size) {
			maxIdx = leftIdx;
		}
		else if (array[leftIdx] <= array[rightIdx]) {
			maxIdx = leftIdx;
		}
		else {
			maxIdx = rightIdx;
		}

		if (array[maxIdx] >= array[rIdx]) {
			return;
		}

		Swap(array, maxIdx, rIdx);

		rIdx = maxIdx;
	}
}

void CreateHeap(int array[], int size) {
	for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
		Heapify(array, size, i);
	}
}


void HeapSort(int array[], int size) {
	CreateHeap(array, size);

	for (int i = 0; i < size; i++) {
		Swap(array, 0, size - 1 - i);
		Heapify(array, size - 1 - i, 0);
	}
}