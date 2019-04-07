class MyStack {
public:
	queue<int>  q;

	/* Initialize your data structure here. */
	/* 在这里初始化数据结构。*/
	MyStack() {
	}

	/* Push element x onto stack. */
	/* 将元素x推入堆栈。*/
	void push(int x) {
		q.push(x);
	}

	/* Removes the element on top of the stack and returns that element. */
	/* 删除堆栈顶部的元素并返回该元素。*/
	int pop() {
		int size = q.size();
		for (int i = 0; i < size - 1; i++) {
			int v = q.front();
			q.pop();
			q.push(v);
		}

		int v = q.front();
		q.pop();
		return v;
	}

	/* Get the top element. */
	/* 获取顶部元素。*/
	int top() {
		int size = q.size();
		for (int i = 0; i < size - 1; i++) {
			int v = q.front();
			q.pop();
			q.push(v);
		}

		int v = q.front();
		q.pop();
		q.push(v);
		return v;
	}

	/* Returns whether the stack is empty. */
	/* 返回堆栈是否为空。*/
	bool empty() {
		return q.empty();
	}
};