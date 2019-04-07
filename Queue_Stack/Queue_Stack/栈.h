#include <stack>

/*

standard	��׼
std::stack<int>	s;

// ѹջ		�����ݷŵ�ջ��
void s.push(100);
// ���� ��ջ	�����ݴ�ջ�ﴦ��
void s.pop();
// ��ȡջ��Ԫ��
int s.top();
// ��ȡջ������
int s.size();
// �ж�ջ�Ƿ�Ϊ��
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
