#include <queue>

void Test() {
	std::queue<int>		q;

	q.push(1);
	q.push(2);
	q.push(3);		// 1, 2, 3

	q.front();		// 1
	q.pop();		// 2, 3
	q.front();		// 2
	q.pop();		// 3
	q.size();		// 1
	q.empty();		// false
	q.front();		// 3
	q.pop();		//
	q.size();		// 0
	q.empty();		// true
}
