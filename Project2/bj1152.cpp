//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    char symbol,first_char;
//    char* s = new char[1000001];
//    gets_s(s, strlen(s));
//    int s_count = 0,  e_count = strlen(s), w_count = 1, size = strlen(s);
//    for (int i = 0; i < size; i++) {
//        symbol = s[i];
//        if (symbol == ' ') {
//            s_count++;
//            break;
//        }
//    }
//    for (int i = size-1; i >= 0; i--) {
//        symbol = s[i];
//        if (symbol == ' ') {
//            e_count--;
//            break;
//        }
//
//    }
//    for (int i = s_count; i < e_count; i++) {
//        symbol = s[i];
//        if (symbol == ' ')
//            w_count++;
//        if (s[size -1] == ' ')
//            w_count--;
//    }
//    cout << w_count;
//}