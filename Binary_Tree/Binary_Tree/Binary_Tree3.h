#pragma once

#include <stdio.h>
#include <assert.h>

/**
 * ʱ�临�Ӷ� O(log(n))
 * �ռ临�Ӷ� O(1)
 * int tree[] �� int size ��������ʾװ�ѵ�ֵ������
 * int rootIdx ��ʾҪ�����Ľ����±�
 */
// ���µ����Ĵ���
void AdjustDown(int tree[], int size, int rootIdx) {
	// ��ô�ж� rootIdx �ǲ���Ҷ��
	// û�����Һ���
	// ��ȫ��������û�����Ӿ�һ��û���Һ���
	// �ж���û������
	// ��Ϊ�����Ǵ���������ģ��жϱ�׼�������ӵ��±��Ƿ�����Խ��
	int leftIdx = 2 * rootIdx + 1;
	int rightIdx = 2 * rootIdx + 2;
	if (leftIdx >= size) {
		// ��Ҷ�ӣ�����
		return;
	}
	// ����Ҷ��
	int minIdx = leftIdx;
	if (rightIdx < size && tree[rightIdx] < tree[leftIdx]) {
		minIdx = rightIdx;
	}
	// ��С���ӵ��±���� minIdx
	if (tree[rootIdx] <= tree[minIdx]) {
		// ��С���Ѿ��Ǹ��ˣ�����ѵ����ʣ�ֹͣ
		return;
	}
	int t = tree[minIdx];
	tree[minIdx] = tree[rootIdx];
	tree[rootIdx] = t;
	// ��������˽���������������Ķ����ʿ��ܱ��ƻ��ˣ���������
	AdjustDown(tree, size, minIdx);
}
void AdjustDown2(int tree[], int size, int rootIdx) {
	// �����Ҷ�ӣ�����������ֱ�ӷ���
	if (2 * rootIdx + 1 >= size) {
		return;
	}
	// �������Ҷ�ӣ��ҵ���С���ӵ��±�
	int minIdx;
	if (2 * rootIdx + 2 >= size) {
		// �Һ��ӵ��±�����Խ���ˣ�����û���Һ���
		minIdx = 2 * rootIdx + 1;
	}
	else if (tree[2 * rootIdx + 1] <= tree[2 * rootIdx + 2]) {
		minIdx = 2 * rootIdx + 1;
	}
	else {
		minIdx = 2 * rootIdx + 2;
	}
	// ����С���ӵ�ֵ �� Ҫ�����ĸ���ֵ���бȽ�
	if (tree[rootIdx] <= tree[minIdx]) {
		// �������ֵ�Ƚ�С������������ֱ�ӷ���
		return;
	}
	else {
		// ���򣬽�������ֵ �� ��С���ӵ�ֵ��
		int t = tree[minIdx];
		tree[minIdx] = tree[rootIdx];
		tree[rootIdx] = t;
		// �����Ѹղ���С���ӵ��±���е���
		AdjustDown2(tree, size, minIdx);
	}
}

// ���Կ���ʱ�临�Ӷ��� O(n * log(n))
// ��ȷ�㣬�� O(n)
// �ҵ����һ����Ҷ�ӽ��,��ʼ�������µ���
void CreateHeap(int tree[], int size) {
	// Ϊʲô��Ҫ���ŵ��������µ�����ǰ��������
	// �������������Ѿ��Ƕ��ˣ��ſ������µ���
	//
	// ���һ�������±��� size - 1��������������ԣ�
	// ���һ����Ҷ�ӽ��������һ������˫��
	// parent = (child - 1) / 2
	// ���� (size - 2) / 2
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
	int array[100];	// ��̬˳���
	int size;		// ���ݸ���
}	Heap;

#include <assert.h>
#include <string.h>
// ��ʼ����������˳���
void HeapInit(Heap *pH, int array[], int size) {
	assert(size <= 100);
	memcpy(pH->array, array, size * sizeof(int));
	pH->size = size;
	CreateHeap(pH->array, pH->size);
}
// ���ϵ����Ĵ���
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
// ͷ��,֮�����ϵ���
void HeapPush(Heap *pH, int v) {
	pH->array[pH->size++] = v;
	AdjustUp(pH->array, pH->size, pH->size - 1);
}
// O(log(n))	ÿ�γ����ǵ�ǰ��Сֵ
// ͷɾ,֮�����µ���
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


// �Ž��򣬽�С��
// ����ѣ��ҳ����ֵ�󣬻��ƻ��ѽṹ
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
