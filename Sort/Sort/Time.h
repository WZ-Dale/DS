#pragma once
#include <stdio.h>
#include "BasicSort.h"
#include "ShellSort.h"
#include "BinaryHeapSort.h"
#include <windows.h>

class �߾��ȼ�ʱ
{
public:
	�߾��ȼ�ʱ(void)
	{
		QueryPerformanceFrequency(&CPUƵ��);
	}

	~�߾��ȼ�ʱ(void) {}

	void ��ʼ()
	{
		QueryPerformanceCounter(&��ʼʱ��);
	}

	void ����()
	{
		QueryPerformanceCounter(&����ʱ��);

		��� = ((double)����ʱ��.QuadPart - (double)��ʼʱ��.QuadPart) / (double)CPUƵ��.QuadPart;
	}

	double �������() const
	{
		return ��� * 1000;
	}

private:
	double ���;

	LARGE_INTEGER ��ʼʱ��;

	LARGE_INTEGER ����ʱ��;

	LARGE_INTEGER CPUƵ��;
};

/*
��ȫ����
��ȫ����
��ȫ���
��ȫ���
*/
// ����һ��size���ȵ���ȫ��������
int * CreateArraySorted(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}
	ShellSort(array, size);
	return array;
}
// ����һ��size���ȵ���ȫ��������
int * CreateArraySortedReverse(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}
	HeapSort(array, size);
	return array;
}
// ����һ��size���ȵ���ȫ�������
int * CreateArrayEqual(int size) {
	int key = rand() % size;
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = key;
	}
	return array;
}
// ����һ��size���ȵ���ȫ�������
int * CreateArrayRandom(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}
	return array;
}

// ð������ʱ��
void TestBubbleSort(int size) {
	printf("ð���������ݸ��� %d ��\n", size / 10000);
	int *array;

	�߾��ȼ�ʱ	��ʱ��;
	array = CreateArraySorted(size);
	��ʱ��.��ʼ();
	BubbleSort(array, size);
	��ʱ��.����();
	printf("���򣺺�ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArraySortedReverse(size);
	��ʱ��.��ʼ();
	BubbleSort(array, size);
	��ʱ��.����();
	printf("���򣺺�ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArrayEqual(size);
	��ʱ��.��ʼ();
	BubbleSort(array, size);
	��ʱ��.����();
	printf("��ȣ���ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArrayRandom(size);
	��ʱ��.��ʼ();
	BubbleSort(array, size);
	��ʱ��.����();
	printf("�������ʱ: %.4f ����\n", ��ʱ��.�������());
}

// ѡ������ʱ��
void TestSelectSort(int size) {
	printf("ѡ���������ݸ��� %d ��\n", size / 10000);
	int *array;

	�߾��ȼ�ʱ	��ʱ��;
	array = CreateArraySorted(size);
	��ʱ��.��ʼ();
	SelectSort(array, size);
	��ʱ��.����();
	printf("���򣺺�ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArraySortedReverse(size);
	��ʱ��.��ʼ();
	SelectSort(array, size);
	��ʱ��.����();
	printf("���򣺺�ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArrayEqual(size);
	��ʱ��.��ʼ();
	SelectSort(array, size);
	��ʱ��.����();
	printf("��ȣ���ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArrayRandom(size);
	��ʱ��.��ʼ();
	SelectSort(array, size);
	��ʱ��.����();
	printf("�������ʱ: %.4f ����\n", ��ʱ��.�������());
}

// ��������ʱ��
void TestInsertSort(int size) {
	printf("�����������ݸ��� %d ��\n", size / 10000);
	int *array;

	�߾��ȼ�ʱ	��ʱ��;
	array = CreateArraySorted(size);
	��ʱ��.��ʼ();
	InsertSort(array, size);
	��ʱ��.����();
	printf("���򣺺�ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArraySortedReverse(size);
	��ʱ��.��ʼ();
	InsertSort(array, size);
	��ʱ��.����();
	printf("���򣺺�ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArrayEqual(size);
	��ʱ��.��ʼ();
	InsertSort(array, size);
	��ʱ��.����();
	printf("��ȣ���ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArrayRandom(size);
	��ʱ��.��ʼ();
	InsertSort(array, size);
	��ʱ��.����();
	printf("�������ʱ: %.4f ����\n", ��ʱ��.�������());
}

// ϣ������ʱ��
void TestShellSort(int size) {
	printf("ϣ���������ݸ��� %d ��\n", size / 10000);
	int *array;

	�߾��ȼ�ʱ	��ʱ��;
	array = CreateArraySorted(size);
	��ʱ��.��ʼ();
	ShellSort(array, size);
	��ʱ��.����();
	printf("���򣺺�ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArraySortedReverse(size);
	��ʱ��.��ʼ();
	ShellSort(array, size);
	��ʱ��.����();
	printf("���򣺺�ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArrayEqual(size);
	��ʱ��.��ʼ();
	ShellSort(array, size);
	��ʱ��.����();
	printf("��ȣ���ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArrayRandom(size);
	��ʱ��.��ʼ();
	ShellSort(array, size);
	��ʱ��.����();
	printf("�������ʱ: %.4f ����\n", ��ʱ��.�������());
}


// ������ʱ��
void TestHeapSort(int size) {
	printf("���������ݸ��� %d ��\n", size / 10000);
	int *array;

	�߾��ȼ�ʱ	��ʱ��;
	array = CreateArraySorted(size);
	��ʱ��.��ʼ();
	HeapSort(array, size);
	��ʱ��.����();
	printf("���򣺺�ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArraySortedReverse(size);
	��ʱ��.��ʼ();
	HeapSort(array, size);
	��ʱ��.����();
	printf("���򣺺�ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArrayEqual(size);
	��ʱ��.��ʼ();
	HeapSort(array, size);
	��ʱ��.����();
	printf("��ȣ���ʱ: %.4f ����\n", ��ʱ��.�������());

	array = CreateArrayRandom(size);
	��ʱ��.��ʼ();
	HeapSort(array, size);
	��ʱ��.����();
	printf("�������ʱ: %.4f ����\n", ��ʱ��.�������());
}
// ����
void Time() {
	TestBubbleSort(2 * 10000);
	TestSelectSort(2 * 10000);
	TestInsertSort(2 * 10000);
	TestShellSort(2 * 10000);
	TestHeapSort(2 * 10000);
}