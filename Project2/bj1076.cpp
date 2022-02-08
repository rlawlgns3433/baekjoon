////#include <stdio.h>
////#include <string.h>
////#include <stdlib.h>
////#pragma warning(disable:4996)
////
////struct resist_num {
////    char color_name[7];
////    long long val;
////    long long time;
////};
////
////int main()
////{
////    struct resist_num resist[10] = { {"black", 0, 1},{"brown", 1, 10},{"red", 2, 100}
////                        ,{"orange", 3, 1000},{"yellow", 4, 10000},{"green", 5, 100000}
////                        ,{"blue", 6, 1000000},{"violet", 7, 10000000},{"grey", 8, 100000000}
////                        ,{"white", 9, 1000000000} };
////    char first[7] = { 0 };
////    char second[7] = { 0 };
////    char third[7] = { 0 };
////
////    long long n1 =0 , n2=0, n3=0, result=0;
////
////    gets_s(first);
////    gets_s(second);
////    gets_s(third);
////
////    for (int i = 0; i < 10; i++) {
////        if (strcmp(first, (resist + i)->color_name) == 0)
////            n1 = (resist + i)->val;
////        if (strcmp(second, (resist + i)->color_name) == 0)
////            n2 = (resist + i)->val;
////        if (strcmp(third, (resist + i)->color_name) == 0)
////            n3 = (resist + i)->time;
////    }
////    result = ((n1 * 10) + n2) * n3;
////    printf("%lld", result);
////}
//
//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable:4996)  
//
//struct resist_num {
//	char color_name[7];
//	long long color_price;
//	long long multiplying_number;
//};
//int main() {
//	struct resist_num resist[10] = { {"black", 0, 1},{"brown", 1, 10},{"red", 2, 100},
//		{"orange", 3, 1000},{"yellow", 4, 10000},{"green", 5, 100000},{"blue",6, 1000000},
//		{"violet", 7, 10000000},{"grey", 8, 100000000},{"white", 9, 1000000000} };
//
//	char word_one[7] = { 0 };
//	char word_two[7] = { 0 };
//	char word_three[7] = { 0 };
//	long long n1 = 0, n2 = 0, n3 = 0;
//	long long answer = 0;
//	gets_s(word_one);
//	gets_s(word_two);
//	gets_s(word_three);
//
//	for (int i = 0; i < 10; i++)
//	{
//		if (strcmp(word_one, (resist + i)->color_name) == 0)
//		{
//			n1 = (resist + i)->color_price;
//		}
//		if (strcmp(word_two, (resist + i)->color_name) == 0)
//		{
//			n2 = (resist + i)->color_price;
//		}
//		if (strcmp(word_three, (resist + i)->color_name) == 0)
//		{
//			n3 = (resist + i)->multiplying_number;
//		}
//	}
//	answer = (n1 * 10 + n2) * n3;
//	printf("%lld", answer);
//
//	return 0;
//}