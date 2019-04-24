#pragma once
#include <stdio.h>
#include "BasicSort.h"

// 归并排序
// 外部排序	首选
void Merge(int array[], int left, int mid, int right, int extra[]) {// 归并两个有序数组
	int i = left;	// 左边区间的下标
	int j = mid;	// 右边区间的下标
	int k = left;	// extra 的下标

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

	// 把 extra 的数据移回来
	for (int x = left; x < right; x++) {
		array[x] = extra[x];
	}
}
// [left, right)
void __MergeSort(int array[], int left, int right, int extra[]) {
	// 直到
	// size == 1	[3, 4)
	if (right == left + 1) {
		return;
	}
	// size == 0
	if (right <= left) {
		return;
	}

	// 1. 把数组平均分成两部分
	int mid = left + (right - left) / 2;
	// [left, mid)
	// [mid, right)
	// 2. 分治算法，排序左右两部分
	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);

	// 3. 合并两个有序数组
	// [left, mid)	[mid, right)
	Merge(array, left, mid, right, extra);
}
void MergeSort(int array[], int size) {
	int *extra = (int *)malloc(sizeof(int)* size);
	__MergeSort(array, 0, size, extra);
	free(extra);
}

// 非递归实现归并排序
void MergeSortNoR(int array[], int size){
	








}

void Test3() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 10, 9 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	MergeSort(array, size);
	PrintArray(array, size);
}