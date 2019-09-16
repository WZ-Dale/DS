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

// 冒泡排序 --- 有序放到后面,搬西瓜原理,将无序中最大的往后放(有大的就交换，往后冒泡)
void BubbleSort(int array[], int size){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size - 1 - i; ++j){
			if (array[j] > array[j + 1]){
				Swap(array, j, j + 1);		// 每次比较成功后,都进行交换
			}
			//PrintArray(array, size);		// 查看冒泡过程
		}
		//printf("\n");						// 查看冒泡过程
	}
}
// 选择排序 --- 有序放到前面,临时变量记录无序中最小数的下标,将其值与无序中第一个数交换(最小的记录下,比完交换)
void SelectSort(int array[], int size){
	for (int i = 0; i < size - 1; ++i){
		int save = i;						// 临时变量,用于记录下标
		for (int j = i + 1; j < size; ++j){
			if (array[j] < array[save]){
				save = j;					// 记录比较后较小数的下标
			}
			//printf("[%d]=%d  ", save, array[save]), PrintArray(array, size);	// 查看选择过程
		}									// 无序中比较完后,save保存的就是无序中最小数的下标
		Swap(array, i, save);				// 将其值与无序中第一个数交换
		//printf("[%d]=%d  ", save, array[save]), PrintArray(array, size);	// 查看选择过程
		//printf("\n");						// 查看选择过程
	}
}
// 插入排序 --- 有序放到前面,拿无序中第一个数跟有序中的数比较大小,找到合适位置插入
void InsertSort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		int save = array[i];				// 保存需要插入的数
		int j;
		for (j = i - 1; j >= 0; --j) {
			if (array[j] < save) {
				break;
			}
			array[j + 1] = array[j];		// 把比save大的往后挪
			printf("save=%d  ", save), PrintArray(array, size);	// 查看插入过程
		}
		array[j + 1] = save;				// 把save插入到合适的位置
		printf("save=%d  ", save), PrintArray(array, size);	// 查看插入过程
		printf("\n");
	}
}

// 测试
void Test() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 6};
	int size = sizeof(array) / sizeof(array[0]);
	printf("排序前数组：\n");
	PrintArray(array, size);
	printf("\n排序过程：\n");

	//BubbleSort(array, size);
	//SelectSort(array, size);
	InsertSort(array, size);

	printf("排序后数组：\n");
	PrintArray(array, size);
}