//#include <iostream>
//using namespace std;
//
//int main()
//{
//	char str[1000000];
//	char symbol, freq;
//	int max = 0,max_value, a[26] = { 0 };
//	cin >> str;
//	for (int i = 0; i < strlen(str); i++)
//	{
//		symbol = toupper(str[i]);
//		switch (symbol) {
//		case 'A':  a[0]++; break; case 'B':  a[1]++; break; case 'C':  a[2]++; break; case 'D':  a[3]++; break; case 'E':  a[4]++; break;
//		case 'F':  a[5]++; break; case 'G':  a[6]++; break; case 'H':  a[7]++; break; case 'I':  a[8]++; break; case 'J':  a[9]++; break;
//		case 'K':  a[10]++; break; case 'L':  a[11]++; break; case 'M':  a[12]++; break; case 'N':  a[13]++; break; case 'O':  a[14]++; break;
//		case 'P':  a[15]++; break; case 'Q':  a[16]++; break; case 'R':  a[17]++; break; case 'S':  a[18]++; break; case 'T':  a[19]++; break;
//		case 'U':  a[20]++; break; case 'V':  a[21]++; break; case 'W':  a[22]++; break; case 'X':  a[23]++; break; case 'Y':  a[24]++; break;
//		case 'Z':  a[25]++; break;
//		}
//	}
//	int count = 0;max_value = a[0];
//	for (int i = 1; i < 26; i++) {
//		if (max_value < a[i]) { max_value = a[i]; max = i; }
//		else if (max_value == a[i]) count++;
//	}
//
//	if (count != 0)
//	{
//		cout << "?";
//		return 0;
//	}
//	if (count == 0) {
//		freq = max+65;
//		cout << freq;
//	}
//}