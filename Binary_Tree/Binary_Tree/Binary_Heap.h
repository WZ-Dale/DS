#pragma once

#include <stdio.h>
#include <assert.h>

/**
 * 时间复杂度 O(log(n))
 * 空间复杂度 O(1)
 * int tree[] 和 int size 合起来表示装堆的值的数组
 * int rootIdx 表示要调整的结点的下标
 */
// 向下调整的代码
void AdjustDown(int tree[], int size, int rootIdx) {
	// 怎么判断 rootIdx 是不是叶子
	// 没有左右孩子
	// 完全二叉树，没有左孩子就一定没有右孩子
	// 判断有没有左孩子
	// 因为我们是存在数组里的，判断标准就是左孩子的下标是否数组越界
	int leftIdx = 2 * rootIdx + 1;
	int rightIdx = 2 * rootIdx + 2;
	if (leftIdx >= size) {
		// 是叶子，结束
		return;
	}
	// 不是叶子
	int minIdx = leftIdx;
	if (rightIdx < size && tree[rightIdx] < tree[leftIdx]) {
		minIdx = rightIdx;
	}
	// 最小孩子的下标就是 minIdx
	if (tree[rootIdx] <= tree[minIdx]) {
		// 最小的已经是根了，满足堆的性质，停止
		return;
	}
	int t = tree[minIdx];
	tree[minIdx] = tree[rootIdx];
	tree[rootIdx] = t;
	// 如果发生了交换，则下面的树的堆性质可能被破坏了，继续调整
	AdjustDown(tree, size, minIdx);
}
void AdjustDown2(int tree[], int size, int rootIdx) {
	// 如果是叶子，调整结束，直接返回
	if (2 * rootIdx + 1 >= size) {
		return;
	}
	// 如果不是叶子，找到最小孩子的下标
	int minIdx;
	if (2 * rootIdx + 2 >= size) {
		// 右孩子的下标数组越界了，所以没有右孩子
		minIdx = 2 * rootIdx + 1;
	}
	else if (tree[2 * rootIdx + 1] <= tree[2 * rootIdx + 2]) {
		minIdx = 2 * rootIdx + 1;
	}
	else {
		minIdx = 2 * rootIdx + 2;
	}
	// 拿最小孩子的值 和 要调整的根的值进行比较
	if (tree[rootIdx] <= tree[minIdx]) {
		// 如果根的值比较小，调整结束，直接返回
		return;
	}
	else {
		// 否则，交换根的值 和 最小孩子的值，
		int t = tree[minIdx];
		tree[minIdx] = tree[rootIdx];
		tree[rootIdx] = t;
		// 继续堆刚才最小孩子的下标进行调整
		AdjustDown2(tree, size, minIdx);
	}
}

// 粗略看，时间复杂度是 O(n * log(n))
// 精确算，是 O(n)
// 找到最后一个非叶子结点,开始整体向下调整
void CreateHeap(int tree[], int size) {
	// 为什么需要倒着调整，向下调整的前提有限制
	// 必须左右子树已经是堆了，才可以向下调整
	//
	// 最后一个结点的下标是 size - 1（根据数组的特性）
	// 最后一个非叶子结点就是最后一个结点的双亲
	// parent = (child - 1) / 2
	// 代入 (size - 2) / 2
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(tree, size, i);
	}
}

#include <stdio.h>

void Test() {
	int array[] = { 6, 9, 13, 7, 1, 8, 2, 4, 5 };
	int size = sizeof(array) / sizeof(int);
	CreateHeap(array, size);
	printf("Hello World\n");
}


typedef struct Heap {
	int array[100];	// 静态顺序表
	int size;		// 数据个数
}	Heap;

#include <assert.h>
#include <string.h>
// 初始化二叉树的顺序表
void HeapInit(Heap *pH, int array[], int size) {
	assert(size <= 100);
	memcpy(pH->array, array, size * sizeof(int));
	pH->size = size;
	CreateHeap(pH->array, pH->size);
}
// 向上调整的代码
void AdjustUp(int tree[], int size, int child) {
	if (child == 0) {
		return;
	}
	int parent = (child - 1) / 2;
	if (tree[child] >= tree[parent]) {
		return;
	}
	int t = tree[child];
	tree[child] = tree[parent];
	tree[parent] = t;
	AdjustUp(tree, size, parent);
}

// log(n)
// 头插,之后向上调整
void HeapPush(Heap *pH, int v) {
	pH->array[pH->size++] = v;
	AdjustUp(pH->array, pH->size, pH->size - 1);
}
// O(log(n))	每次出的是当前最小值
// 头删,之后向下调整
int HeapPop(Heap *pH) {
	int v = pH->array[0];
	pH->array[0] = pH->array[pH->size - 1];
	pH->size--;
	AdjustDown(pH->array, pH->size, 0);
	return v;
}
void Test2() {
	int array[] = { 9, 5, 7, 3, 8, 4, 2, 1, 0 };
	int size = sizeof(array) / sizeof(int);
	Heap heap;
	HeapInit(&heap, array, size);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", HeapPop(&heap));
	}
	printf("After pop\n");
	for (int i = 0; i < 3; i++) {
		HeapPush(&heap, i);
	}
	printf("After push\n");
	int size2 = heap.size;
	for (int i = 0; i < size2; i++) {
		printf("%d\n", HeapPop(&heap));
	}
}


// 排降序，建小堆
// 建大堆，找出最大值后，会破坏堆结构
void HeapSort(int array[], int size) {
	CreateHeap(array, size);
	for (int i = 0; i < size; i++) {
		int t = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = t;
		AdjustDown(array, size - 1 - i, 0);
	}
}
void Test3() {
	int array[] = { 9, 4, 5, 7, 3, 8, 6, 2, 4, 0, 1, 7 };
	int size = sizeof(array) / sizeof(int);
	HeapSort(array, size);
	printf("hello\n");
}
