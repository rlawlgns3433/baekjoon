#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Segment_Tree {
private:
	int leaf;
	int tree_size;
	int i;

public:
	vector<long long> tree;
	vector<long long> sum_vector;

	Segment_Tree()
	{
		int i = 0;
		this->leaf = 0;
		tree_size = 0;
	}
	Segment_Tree(int l_size)
	{
		i = 0;
		this->leaf = l_size;
		tree_size = 0;

		Calc_Tree_size();
		tree.resize(tree_size, 0);
	}

	void Calc_Tree_size()
	{
		while (true)
		{
			long long sz = pow(2, i);
			if (sz >= leaf)
			{
				tree_size = sz * 2;
				return;
			}
			i++;
		}
	}

	int Get_Tree_Size()
	{
		return tree_size;
	}

	void Update_Number(int idx, long long number)
	{
		int tree_idx = Get_Tree_Index(idx);
		long long prev_number = tree[tree_idx];
		long long diff = number - prev_number;

		tree[tree_idx] = number;
		while (tree_idx >= 1)
		{
			tree[tree_idx / 2] += diff;
			tree_idx /= 2;
		}
	}

	int Get_Tree_Index(int idx)
	{
		return idx + pow(2, i) - 1;
	}

	long long Get_Sum_Of_Range(int start_index, int end_index)
	{
		long long sum = 0;
		while (end_index >= start_index)
		{
			if (start_index % 2 == 1)
			{
				sum_vector.push_back(tree[start_index]);
				start_index = (start_index + 1) / 2;
			}
			else if (start_index % 2 == 0)
			{
				start_index = (start_index + 1) / 2;
			}

			if (end_index % 2 == 1)
			{
				end_index = (end_index - 1) / 2;
			}
			else if (end_index % 2 == 0)
			{
				sum_vector.push_back(tree[end_index]);
				end_index = (end_index - 1) / 2;
			}
		}

		for (long long value : sum_vector)
		{
			sum += value;
		}

		sum_vector.clear();
		return sum;
	}

	void Fill_Sum_Tree()
	{
		for (int i = tree_size - 1; i > 0; i--)
		{
			tree[i / 2] += tree[i];
		}
	}

	void Print_Tree()
	{
		for (int idx = 0; idx < tree_size; idx++)
		{
			cout << idx << " : " << tree[idx] << '\n';
		}
	}
};

int main()
{
	int N, M, K;

	cin >> N >> M >> K;

	Segment_Tree* st = new Segment_Tree(N);

	for (int i = st->Get_Tree_Size() / 2; i < st->Get_Tree_Size() / 2 + N; i++)
	{
		cin >> st->tree[i];
	}
	st->Fill_Sum_Tree();

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			st->Update_Number(b, c);
		}
		else
		{
			cout << st->Get_Sum_Of_Range(st->Get_Tree_Index(b), st->Get_Tree_Index(c)) << '\n';
		}
	}
}