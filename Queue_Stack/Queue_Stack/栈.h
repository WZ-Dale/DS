#include <stack>

/*

standard	标准
std::stack<int>	s;

// 压栈		把数据放到栈里
void s.push(100);
// 弹出 弹栈	把数据从栈里处理
void s.pop();
// 获取栈顶元素
int s.top();
// 获取栈内数据
int s.size();
// 判断栈是否为空
bool s.empty();		true | false

*/


void Test() {
	std::stack<int>	 s;
	s.push(1);	s.push(3);	s.push(9);	// 1, 3, 9
	printf("%d\n", s.top());			// 9
	s.pop();							// 1, 3
	printf("%d\n", s.top());			// 3
	s.pop();							// 1
	printf("%d\n", s.top());			// 1
	printf("size: %d\n", s.size());		// 1
}
