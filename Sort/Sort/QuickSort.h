#pragma once
#include <stdio.h>
#include "BasicSort.h"

// 1.Hover法
// 对数组中[low, high] 的区间做分组
// 基准值是 array[low]
int Partition1(int array[], int low, int high){
	int begin = low;// 从基准值位置开始
	int end = high;
	int pivot = array[low];// 保存基准值
	// (begin, end) 的区间是没有被比较过的数据
	while (begin < end){
		while (begin < end && array[end] >= pivot){// 重点: 如果基准值在左边，需要从右边开始走
			end--;
		}
		// 此时array[end] 比基准值小了
		while (begin < end && array[begin] <= pivot){
			begin++;
		}
		// 此时array[begin] 比基准值大了
		Swap(array, begin, end);// 交换 begin 和 end 下标处的数据
	}
	// low 基准值
	// [low + 1, begin] 比基准值小
	// [begin + 1, high] 比基准值大
	Swap(array, low, begin);// 把基准值和比它小的最后一个数交换
	return begin;
}

// 2.挖坑法
// 对数组中 [low, high] 的区间做分组
// 基准值是 array[low]
int Partition2(int array[], int low, int high){
	int begin = low;// 从基准值位置开始	// begin 是坑的下标
	int end = high;
	int pivot = array[low];	// 保存基准值
	// (begin, end) 的区间是没有被比较过的数据
	while (begin < end){
		while (begin < end && array[end] >= pivot){// 重点: 如果基准值在左边，需要从右边开始走
			end--;
		}
		// 此时array[end] 比基准值小了
		// 此时坑的下标是 begin
		array[begin] = array[end];// 拿end下标处的值填坑,end会变为坑
		// 此时坑的下标是 end
		while (begin < end && array[begin] <= pivot){
			begin++;
		}
		// 此时array[begin] 比基准值大了
		// 此时坑的下标是 end
		array[end] = array[begin];// 拿begin下标处的值填坑,begin会变为坑
		// 此时坑的下标是 begin
	}
	array[begin] = pivot;// 把基准值放的begin坑中
	return begin;
}

// 3.前后指针（下标）法
// 对数组中 [low, high] 的区间做分组
// 基准值是 array[low]
int Partition3(int array[], int low, int high){
	int d = low + 1;// 基准值为array[low]
	int i = low + 1;
	while (i <= high){// 拿i去寻找比基准值大的,i++
		if (array[i] < array[low]){// 如果i下标处的值小于基准值,则交换d和i下标处的值
			Swap(array, d, i);
			d++;// d下标左边的都比基准值小
		}
		i++;
	}
	Swap(array, low, d - 1);// 把基准值和比它小的最后一个数交换
	return d - 1;
}

// 快速排序
// 需要排序的区间是 [low, high]
void _QuickSort(int array[], int low, int high){
	if (low > high || low == high){	// 直到区间长度为0,或者区间长度为1,表示区间内的数已经有序
		return;
	}
	// 1. 找基准值，选最左边，基准值的下标是 low
	// 2. 遍历整个区间，把小的放左，大的放右，返回基准值所在下标
	int partition = Partition1(array, low, high);
	// 3. 区间被分成三部分
	// [low, pivotIdx - 1] 小
	// [pivotIdx, pivotIdx] 有序
	// [pivotIdx + 1, high] 大
	// 分治算法，分别处理所有两个小区间
	_QuickSort(array, low, partition - 1);
	_QuickSort(array, partition + 1, high);
}
void QuickSort(int array[], int size){
	_QuickSort(array, 0, size - 1);
}

//非递归实现快速排序(使用的是调用栈)
#include <stack>
void QuickSortNoR(int array[], int size) {
	std::stack<int>	stack;
	stack.push(0);			// low
	stack.push(size - 1);	// high

	while (!stack.empty()) {
		int high = stack.top();
		stack.pop();
		int low = stack.top();
		stack.pop();

		if (low >= high) {
			continue;
		}

		int pivotIdx = Partition1(array, low, high);
		// [low, pivotIdx - 1]
		stack.push(low);
		stack.push(pivotIdx - 1);
		// [pivotIdx + 1, high]
		stack.push(pivotIdx + 1);
		stack.push(high);
	}
}

// 测试
void Test2() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 6 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArray(array, size);
	//QuickSort(array, size);
	QuickSortNoR(array, size);
	PrintArray(array, size);
}
