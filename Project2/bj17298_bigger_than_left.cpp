//#include <iostream>
//#include <stack>
//using namespace std;
//
//int A[1000000];
//int S[1000000];
//stack<int> stk;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//		cin >> S[i];
//
//	for (int i = n - 1; i >= 0; i--)
//	{
//		while (!stk.empty() && stk.top() <= S[i])
//			stk.pop();
//
//		if (stk.empty()) A[i] = -1;
//		else A[i] = stk.top();
//
//		stk.push(S[i]);
//	}
//
//	for (int i = 0; i < n; i++)
//		cout << A[i] << ' ';
//}