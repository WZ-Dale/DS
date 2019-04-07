class Solution {
public:
	// 字符串类型
	// char 类型的顺序表
	// size() 返回字符个数
	bool isValid(string s) {
		stack<char> st;
		int size = s.size();
		for (int i = 0; i < size; i++) {
			char ch = s[i];
			switch (ch) {
				case '(':
				case '[':
				case '{':
					st.push(ch);
					break;
				case ')':
				case ']':
				case '}': {
					if (st.empty()) {
						// 右括号多
						return false;
					}
					char left = st.top();
					if ((left == '(' && ch == ')')
						|| (left == '[' && ch == ']')
						|| (left == '{' && ch == '}')) {
						st.pop();
					}
					else {
						// 左右不是一种括号
						return false;
					}
				}
			}
		}
		if (!st.empty()) {
			// 左括号多
			return false;
		}
		return true;
	}
};
