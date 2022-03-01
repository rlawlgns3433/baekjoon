#include <iostream>
#include <malloc.h>
using namespace std;

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	int N; cin >> N;
	int* list = (int*)malloc(sizeof(int) * N * N);
	for (int i = 0; i < N * N; i++) {
		cin >> list[i];
	}
	
}