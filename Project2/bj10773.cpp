//#include <iostream>
//#include <stack>
//
//int main()
//{
//    std::stack<int> stk;
//    int n, temp, sum = 0;
//
//    std::cin >> n;
//    for (int i = 0; i < n; i++) {
//        std::cin >> temp;
//        if (temp == 0) stk.pop();
//        else stk.push(temp);
//    }
//
//    for (int i = stk.size(); i != 0; i--) {
//        sum += stk.top();
//        stk.pop();
//    }
//    std::cout << sum;
//}