//#include <iostream>
//#include <stack>
//#include <string>
//#include <string.h>
//using namespace std;
//
//
//int testpair(char* str) {
//	stack<char> stack;
//	int size = strlen(str);
//	char symbol, open_pair;
//	for (int i = 0; i < size; i++) {
//		symbol = str[i];
//		switch (symbol) {
//		case '(': case '{': case '[': stack.push(symbol); break;
//		case ')': case '}': case ']' :
//			if (stack.top() == NULL) return 0;
//			else {
//				open_pair = stack.top(); stack.pop();
//				if ((open_pair == '(' && symbol != ')') ||
//					(open_pair == '{' && symbol != '}') ||
//					(open_pair == '[' && symbol != ']')) return 0;
//				else break;
//			}
//		}
//	}
//	if (stack.top() == NULL) return 1;
//	else return 0;
//}
//
//int main()
//{
//	int n;
//	char str[51];
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> str;
//		if (testpair(str) == 1) cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//}