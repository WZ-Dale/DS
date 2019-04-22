#pragma once
#include <stdio.h>
#include "BasicSort.h"
#include "ShellSort.h"
#include "BinaryHeapSort.h"
#include <windows.h>

class 高精度计时
{
public:
	高精度计时(void)
	{
		QueryPerformanceFrequency(&CPU频率);
	}

	~高精度计时(void) {}

	void 开始()
	{
		QueryPerformanceCounter(&开始时间);
	}

	void 结束()
	{
		QueryPerformanceCounter(&结束时间);

		间隔 = ((double)结束时间.QuadPart - (double)开始时间.QuadPart) / (double)CPU频率.QuadPart;
	}

	double 间隔毫秒() const
	{
		return 间隔 * 1000;
	}

private:
	double 间隔;

	LARGE_INTEGER 开始时间;

	LARGE_INTEGER 结束时间;

	LARGE_INTEGER CPU频率;
};

/*
完全有序
完全逆序
完全相等
完全随机
*/
// 产生一个size长度的完全有序数组
int * CreateArraySorted(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}
	ShellSort(array, size);
	return array;
}
// 产生一个size长度的完全逆序数组
int * CreateArraySortedReverse(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}
	HeapSort(array, size);
	return array;
}
// 产生一个size长度的完全相等数组
int * CreateArrayEqual(int size) {
	int key = rand() % size;
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = key;
	}
	return array;
}
// 产生一个size长度的完全随机数组
int * CreateArrayRandom(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}
	return array;
}

// 冒泡排序时间
void TestBubbleSort(int size) {
	printf("冒泡排序：数据个数 %d 万\n", size / 10000);
	int *array;

	高精度计时	计时器;
	array = CreateArraySorted(size);
	计时器.开始();
	BubbleSort(array, size);
	计时器.结束();
	printf("有序：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArraySortedReverse(size);
	计时器.开始();
	BubbleSort(array, size);
	计时器.结束();
	printf("逆序：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArrayEqual(size);
	计时器.开始();
	BubbleSort(array, size);
	计时器.结束();
	printf("相等：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArrayRandom(size);
	计时器.开始();
	BubbleSort(array, size);
	计时器.结束();
	printf("随机：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());
}

// 选择排序时间
void TestSelectSort(int size) {
	printf("选择排序：数据个数 %d 万\n", size / 10000);
	int *array;

	高精度计时	计时器;
	array = CreateArraySorted(size);
	计时器.开始();
	SelectSort(array, size);
	计时器.结束();
	printf("有序：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArraySortedReverse(size);
	计时器.开始();
	SelectSort(array, size);
	计时器.结束();
	printf("逆序：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArrayEqual(size);
	计时器.开始();
	SelectSort(array, size);
	计时器.结束();
	printf("相等：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArrayRandom(size);
	计时器.开始();
	SelectSort(array, size);
	计时器.结束();
	printf("随机：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());
}

// 插入排序时间
void TestInsertSort(int size) {
	printf("插入排序：数据个数 %d 万\n", size / 10000);
	int *array;

	高精度计时	计时器;
	array = CreateArraySorted(size);
	计时器.开始();
	InsertSort(array, size);
	计时器.结束();
	printf("有序：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArraySortedReverse(size);
	计时器.开始();
	InsertSort(array, size);
	计时器.结束();
	printf("逆序：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArrayEqual(size);
	计时器.开始();
	InsertSort(array, size);
	计时器.结束();
	printf("相等：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArrayRandom(size);
	计时器.开始();
	InsertSort(array, size);
	计时器.结束();
	printf("随机：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());
}

// 希尔排序时间
void TestShellSort(int size) {
	printf("希尔排序：数据个数 %d 万\n", size / 10000);
	int *array;

	高精度计时	计时器;
	array = CreateArraySorted(size);
	计时器.开始();
	ShellSort(array, size);
	计时器.结束();
	printf("有序：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArraySortedReverse(size);
	计时器.开始();
	ShellSort(array, size);
	计时器.结束();
	printf("逆序：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArrayEqual(size);
	计时器.开始();
	ShellSort(array, size);
	计时器.结束();
	printf("相等：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArrayRandom(size);
	计时器.开始();
	ShellSort(array, size);
	计时器.结束();
	printf("随机：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());
}


// 堆排序时间
void TestHeapSort(int size) {
	printf("堆排序：数据个数 %d 万\n", size / 10000);
	int *array;

	高精度计时	计时器;
	array = CreateArraySorted(size);
	计时器.开始();
	HeapSort(array, size);
	计时器.结束();
	printf("有序：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArraySortedReverse(size);
	计时器.开始();
	HeapSort(array, size);
	计时器.结束();
	printf("逆序：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArrayEqual(size);
	计时器.开始();
	HeapSort(array, size);
	计时器.结束();
	printf("相等：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());

	array = CreateArrayRandom(size);
	计时器.开始();
	HeapSort(array, size);
	计时器.结束();
	printf("随机：耗时: %.4f 毫秒\n", 计时器.间隔毫秒());
}
// 测试
void Time() {
	TestBubbleSort(2 * 10000);
	TestSelectSort(2 * 10000);
	TestInsertSort(2 * 10000);
	TestShellSort(2 * 10000);
	TestHeapSort(2 * 10000);
}