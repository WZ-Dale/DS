#pragma once

namespace Peixinchen {
	void Sort(int array[], int size);
}

// 绝对的
Peixinchen::Sort();

// 指定
using Peixinchen::Sort;

Sort();

// 解包
using Peixinchen;

Sort();


// 结构体的进化版		类(class)
struct SeqList {
	// 成员变量	也就是 c 里的字段
	int array[100];
	int size;

	void PushBack(int v);	// 成员函数/成员方法
};

struct SeqList	seqList;		// 对象	object	instance 实例
struct SeqList	*pSeqList;	// 经过申请空间

seqList.PushBack(100);
pSeqList->PushBack(100);

// 模板		泛型编程
struct SeqList < typename T > {
	// 成员变量	也就是 c 里的字段
	T array[100];
	int size;

	void PushBack(T v);	// 成员函数/成员方法
};

SeqList<int>	sli;
SeqList<float>	slf;
