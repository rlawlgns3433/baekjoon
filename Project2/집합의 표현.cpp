#include <stdio.h>

int n, m;
int arr[1000001];

int Find(int a)
{
	if (arr[a] == a)
		return a;
	else
		return arr[a] = Find(arr[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b)
		return;

	arr[a] = b;
}

int main()
{
	scanf("%d %d", &n, &m);

	int command, a, b;

	for (int i = 0; i <= n; ++i)
	{
		arr[i] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &command, &a, &b);

		if (command == 1)
		{
			if (Find(a) == Find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			Union(a, b);
		}
	}
}