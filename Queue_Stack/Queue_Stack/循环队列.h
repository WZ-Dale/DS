class MyCircularQueue {
public:
	int size;
	int capacity;
	int *array;

	int front;
	int rear;

	/* Initialize your data structure here. Set the size of the queue to be k. */
	/* 在这里初始化数据结构。将队列的大小设置为k。*/
	MyCircularQueue(int k) {
		array = (int *)malloc(sizeof(int)* k);
		size = 0;
		capacity = k;

		front = 0;
		rear = 0;
	}

	/* Insert an element into the circular queue. Return true if the operation is successful. */
	/* 在循环队列中插入一个元素。如果操作成功，返回true。*/
	bool enQueue(int value) {
		if (size >= capacity) {
			return false;
		}

		array[rear] = value;
		rear = (rear + 1) % capacity;
		size++;
		return true;
	}

	/* Delete an element from the circular queue. Return true if the operation is successful. */
	/* 从循环队列中删除一个元素。如果操作成功，返回true。*/
	bool deQueue() {
		if (size <= 0) {
			return false;
		}

		size--;
		front = (front + 1) % capacity;
		return true;
	}

	/* Get the front item from the queue. */
	/* 从队列中获取前端项。*/
	int Front() {
		if (size <= 0) {
			return -1;
		}
		return array[front];
	}

	/* Get the last item from the queue. */
	/* 从队列中获取最后一项。*/
	int Rear() {
		if (size <= 0) {
			return -1;
		}

		int index = (rear - 1 + capacity) % capacity;
		return array[index];
	}

	/* Checks whether the circular queue is empty or not. */
	/* 检查循环队列是否为空。*/
	bool isEmpty() {
		return size == 0;	//判断size == 0
	}

	/* Checks whether the circular queue is full or not. */
	/* 检查循环队列是否已满。*/
	bool isFull() {
		return size == capacity;
	}
};