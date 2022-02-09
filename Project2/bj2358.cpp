//#include <iostream>
//#include <vector>
//
//void my2358()
//{
//    std::vector<long long> x;
//    std::vector<long long> y;
//    long long temp_x, temp_y, n, count = 0;
//    std::cin >> n;
//    for (long long i = 0; i < n; i++) {
//        std::cin >> temp_x >> temp_y;
//        x.emplace_back(temp_x); y.emplace_back(temp_y);
//    }
//    for (long long i = 0; i < n - 1; i++) {
//        if (x[i] == x[i + 1])
//            count++;
//        if (y[i] == y[i + 1])
//            count++;
//    }
//    for (long long i = 0; i < n; i++)
//        if (x[i] == y[i])
//            count++;
//    std::cout << count;
//}
//
//
//#include <map>
//int main()
//{
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    std::cout.tie(NULL);
//    int t;
//    std::cin >> t;
//    std::map<int, int> dotx, doty;
//    for (int i = 1; i <= t; i++) {
//        int x, y;
//        std::cin >> x >> y;
//        dotx[x]++;
//        doty[y]++;
//    }
//
//
//    int sum = 0;
//    for (auto i = dotx.begin(); i != dotx.end(); i++){
//        if (i->second >= 2)
//            std::cout << i->second << "\n";
//            sum++;}
//    for (auto i = doty.begin(); i != doty.end(); i++) {
//        if (i->second >= 2)
//            std::cout << i->second << "\n";
//        sum++;
//    }
//
//    std::cout << sum;
//}