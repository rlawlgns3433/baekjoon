//#include <stack>
//#include <vector>
//#include <iostream>
//#include <time.h>
//using namespace std;
//
//int main()
//{
//	stack<unsigned> stk;
//	ios::sync_with_stdio(0); cin.tie(0);
//	unsigned n, input, temp = 1;
//	cin >> n;
//
//	vector<char> v;
//	for (unsigned i = 0; i < n; i++) {
//		cin >> input;
//		if (stk.empty() == 0&& stk.top() == input)
//		{
//			stk.pop();
//			v.emplace_back('-');
//		}
//		else
//		{
//			for (unsigned j = temp; j <= input; j++)
//			{
//				stk.push(j);
//				v.emplace_back('+');
//			}
//			if (stk.top() == input)
//			{
//				stk.pop();
//				v.emplace_back('-');
//			}
//			else
//			{
//				cout << "NO";
//				return 0;
//			}
//			temp = input + 1;
//		}
//	}
//
//	for (auto& e : v)
//		cout << e << endl;
//
//	return 0;
//}