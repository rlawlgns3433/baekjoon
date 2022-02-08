//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    char p[81];
//    int n, score, count;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        score = 0;
//        count = 0;
//        scanf("%s", p);
//        int size = sizeof(p) / sizeof(p[0]);
//        for(int j = 0; j < size; j++){
//            if (p[j] == 'O') {
//                count++;
//                score += count;
//            }
//            else count = 0;
//        }
//        for(int j = 0; j < 81; j++)
//            p[j] = 'X';
//        printf("%d\n", score);
//    }
//}