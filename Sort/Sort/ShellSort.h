#pragma once
#include <stdio.h>
#include "BasicSort.h"

// 插入排序(常用)
void InsertSort3(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int save = array[i];			// 保存需要插入的数
		int j;
		for (j = i - 1; j >= 0; --j) {
			if (array[j] <= save) {
				break;
			}
			array[j + 1] = array[j];	// 把比save大的往后挪
		}
		array[j + 1] = save;			// 把save插入到合适的位置
	}
}
// 希尔排序 --- 快速排序的升级版
// 分组插排
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
	while (gap != 1) {			// 当分组的长度为1时,就排好了
		gap = gap / 3 + 1;		// 分组算法
		InsertSortWithGap(array, size, gap);
	}
}
// 测试
void Test1() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 6 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArray(array, size);
	ShellSort(array, size);
	PrintArray(array, size);
}