class MyQueue {
public:
	stack<int>  in;
	stack<int>  out;

	/* Initialize your data structure here. */
	/* 在这里初始化数据结构。*/
	MyQueue() {

	}

	/* Push element x to the back of queue. */
	/* 将元素x推到队列的后面。*/
	void push(int x) {
		in.push(x);
	}

	/* Removes the element from in front of queue and returns that element. */
	/* 从队列前面移除元素并返回该元素。*/
	int pop() {
		if (out.empty()) {
			while (!in.empty()) {
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}

		int v = out.top();
		out.pop();
		return v;
	}

	/* Get the front element. */
	/* 获取front元素。*/
	int peek() {
		if (out.empty()) {
			while (!in.empty()) {
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}

		int v = out.top();
		return v;
	}

	/* Returns whether the queue is empty. */
	/* 返回队列是否为空。*/
	bool empty() {
		return in.empty() && out.empty();
	}
};