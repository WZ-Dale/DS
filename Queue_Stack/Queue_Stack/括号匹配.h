class Solution {
public:
	// �ַ�������
	// char ���͵�˳���
	// size() �����ַ�����
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
						// �����Ŷ�
						return false;
					}
					char left = st.top();
					if ((left == '(' && ch == ')')
						|| (left == '[' && ch == ']')
						|| (left == '{' && ch == '}')) {
						st.pop();
					}
					else {
						// ���Ҳ���һ������
						return false;
					}
				}
			}
		}
		if (!st.empty()) {
			// �����Ŷ�
			return false;
		}
		return true;
	}
};
