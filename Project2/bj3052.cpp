#include <iostream>
using namespace std;

int main()
{
	int input, result = 0;
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> input;
		a[i] = input % 42;
	}
	for (int i = 0; i < 10; i++) {
		int count = 0;
		for (int j = i + 1; j < 10; j++)
			if (a[i] == a[j])
				count++;
		if (count == 0) result++;
	}
	cout << result;

}