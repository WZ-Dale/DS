#pragma once
#include <stdio.h>
#include "BasicSort.h"

// 1.Hover��
// ��������[low, high] ������������
// ��׼ֵ�� array[low]
int Partition1(int array[], int low, int high){
	int begin = low;// �ӻ�׼ֵλ�ÿ�ʼ
	int end = high;
	int pivot = array[low];// �����׼ֵ
	// (begin, end) ��������û�б��ȽϹ�������
	while (begin < end){
		while (begin < end && array[end] >= pivot){// �ص�: �����׼ֵ����ߣ���Ҫ���ұ߿�ʼ��
			end--;
		}
		// ��ʱarray[end] �Ȼ�׼ֵС��
		while (begin < end && array[begin] <= pivot){
			begin++;
		}
		// ��ʱarray[begin] �Ȼ�׼ֵ����
		Swap(array, begin, end);// ���� begin �� end �±괦������
	}
	// low ��׼ֵ
	// [low + 1, begin] �Ȼ�׼ֵС
	// [begin + 1, high] �Ȼ�׼ֵ��
	Swap(array, low, begin);// �ѻ�׼ֵ�ͱ���С�����һ��������
	return begin;
}

// 2.�ڿӷ�
// �������� [low, high] ������������
// ��׼ֵ�� array[low]
int Partition2(int array[], int low, int high){
	int begin = low;// �ӻ�׼ֵλ�ÿ�ʼ	// begin �ǿӵ��±�
	int end = high;
	int pivot = array[low];	// �����׼ֵ
	// (begin, end) ��������û�б��ȽϹ�������
	while (begin < end){
		while (begin < end && array[end] >= pivot){// �ص�: �����׼ֵ����ߣ���Ҫ���ұ߿�ʼ��
			end--;
		}
		// ��ʱarray[end] �Ȼ�׼ֵС��
		// ��ʱ�ӵ��±��� begin
		array[begin] = array[end];// ��end�±괦��ֵ���,end���Ϊ��
		// ��ʱ�ӵ��±��� end
		while (begin < end && array[begin] <= pivot){
			begin++;
		}
		// ��ʱarray[begin] �Ȼ�׼ֵ����
		// ��ʱ�ӵ��±��� end
		array[end] = array[begin];// ��begin�±괦��ֵ���,begin���Ϊ��
		// ��ʱ�ӵ��±��� begin
	}
	array[begin] = pivot;// �ѻ�׼ֵ�ŵ�begin����
	return begin;
}

// 3.ǰ��ָ�루�±꣩��
// �������� [low, high] ������������
// ��׼ֵ�� array[low]
int Partition3(int array[], int low, int high){
	int d = low + 1;// ��׼ֵΪarray[low]
	int i = low + 1;
	while (i <= high){// ��iȥѰ�ұȻ�׼ֵ���,i++
		if (array[i] < array[low]){// ���i�±괦��ֵС�ڻ�׼ֵ,�򽻻�d��i�±괦��ֵ
			Swap(array, d, i);
			d++;// d�±���ߵĶ��Ȼ�׼ֵС
		}
		i++;
	}
	Swap(array, low, d - 1);// �ѻ�׼ֵ�ͱ���С�����һ��������
	return d - 1;
}

// ��������
// ��Ҫ����������� [low, high]
void _QuickSort(int array[], int low, int high){
	if (low > high || low == high){	// ֱ�����䳤��Ϊ0,�������䳤��Ϊ1,��ʾ�����ڵ����Ѿ�����
		return;
	}
	// 1. �һ�׼ֵ��ѡ����ߣ���׼ֵ���±��� low
	// 2. �����������䣬��С�ķ��󣬴�ķ��ң����ػ�׼ֵ�����±�
	int partition = Partition1(array, low, high);
	// 3. ���䱻�ֳ�������
	// [low, pivotIdx - 1] С
	// [pivotIdx, pivotIdx] ����
	// [pivotIdx + 1, high] ��
	// �����㷨���ֱ�����������С����
	_QuickSort(array, low, partition - 1);
	_QuickSort(array, partition + 1, high);
}
void QuickSort(int array[], int size){
	_QuickSort(array, 0, size - 1);
}

//�ǵݹ�ʵ�ֿ�������(ʹ�õ��ǵ���ջ)
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

// ����
void Test2() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 6 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArray(array, size);
	//QuickSort(array, size);
	QuickSortNoR(array, size);
	PrintArray(array, size);
}
