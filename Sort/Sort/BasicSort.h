#pragma once
#include <stdio.h>

void Swap(int array[], int a, int b){
	int t = array[a];
	array[a] = array[b];
	array[b] = t;
}
// 冒泡排序 --- 有序放到后面,搬西瓜原理,将无序中最大的往后放(有大的就交换)
void BubbleSort(int array[], int size){
	int i, j;
	for (i = 0; i < size - 1; ++i){
		for (j = i + 1; j < size; ++j){
			if (array[i] > array[j]){
				Swap(array, i, j);		// 每次比较成功后,都进行交换
			}
		}
	}
}
// 选择排序 --- 有序放到后面,小本本记录下标位置,最后比较晚往后放(最大的记录下,比完放)
void SelectSort(int array[], int size){
	int i, j;
	for (i = 0; i < size; ++i){
		int save = 0;					// 拿一个小本本,用于记录小标
		for (j = 0; j < size - i; ++j){
			if (array[j] > array[save]){
				save = j;				// 记录比较后较大大下标
			}
		}								// 比较完后,save保存的就是最大的下标
		Swap(array, save, size - 1 - i);
	}
}
// 插入排序(精简版) --- 有序放到前面,拿无序中的数跟有序中的数比较大小,找到合适位置插入
void InsertSort(int array[], int size) {
	int i;
	for (i = 1; i < size; ++i){
		int save = array[i];			// 保存需要插入的数
		while (i > 0 && array[i - 1] > save){
			array[i] = array[i - 1];	// 把比save大的往后挪
			--i;
		}
		array[i] = save;				// 把save插入到合适的位置
	}
}
// 插入排序(常用)
void InsertSort2(int array[], int size) {
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
void PrintArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
// 测试
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