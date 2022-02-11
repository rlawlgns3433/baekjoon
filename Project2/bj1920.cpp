//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//long a[100000];
//long n;
//
//void bj1920_exceed_time()
//{
//    int input, n, m, result = 0;
//    scanf("%d", &n);
//    std::vector<int> a, b;
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &input);
//        a.push_back(input);
//    }
//    std::cin >> m;
//    for (int i = 0; i < m; i++) {
//        scanf("%d", &input);
//        b.push_back(input);
//    }
//    for (int j = 0; j < m; j++) {
//        int count = 0;
//        for (int i = 0; i < n; i++) {
//            if (a[i] == b[j])
//                count++;
//        }
//        if (count == 0)
//            printf("0\n");
//        else printf("1\n");
//    }
//}
//
//
//
//bool bsearch(long b)
//{
//    long left = 0, right = n - 1;
//    long mid, mid_value;
//    while (left <= right)
//    {
//        mid = (left + right) >> 1;
//        mid_value = a[mid];
//        if (mid_value == b)return true;
//        else if (b < mid_value) right = mid - 1;
//        else if (mid_value < b) left = mid + 1;
//    }
//
//    return false;
//}
//
//int main()
//{
//    scanf("%ld", &n);
//    for (long i = 0; i < n; ++i)
//        scanf("%ld", &a[i]);
//    std::sort(a, a + n);
//    long m;
//    scanf("%ld", &m);
//    long b;
//    for (long i = 0; i < m; ++i)
//    {
//        scanf("%ld", &b);
//        if (bsearch(b))printf("1\n");
//        else printf("0\n");
//    }
//
//    return 0;
//}

