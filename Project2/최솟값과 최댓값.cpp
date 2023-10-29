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
	vector<int> tree;
	vector<long long> sum_vector;
	vector<int> min_tree;
	vector<int> max_tree;

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

		min_tree.resize(tree_size, 1000000000);
		max_tree.resize(tree_size, 0);
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

	int Get_Min_Of_Range(int start_index, int end_index)
	{
		int min_value = 10e9;

		while (end_index >= start_index)
		{
			if (start_index % 2 == 1)
			{
				min_value = min(min_value, min_tree[start_index]);
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
				min_value = min(min_value, min_tree[end_index]);
				end_index = (end_index - 1) / 2;
			}
		}
		return min_value;
	}

	int Get_Max_Of_Range(int start_index, int end_index)
	{
		int max_value = 0;

		while (end_index >= start_index)
		{
			if (start_index % 2 == 1)
			{
				max_value = max(max_value, max_tree[start_index]);
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
				max_value = max(max_value, max_tree[end_index]);
				end_index = (end_index - 1) / 2;
			}
		}

		return max_value;
	}

	void Fill_Sum_Tree()
	{
		for (int i = tree_size - 1; i > 0; i--)
		{
			tree[i / 2] += tree[i];
		}
	}

	void Fill_Min_Tree()
	{
		for (int i = tree_size - 1; i > 0; i--)
		{
			min_tree[i / 2] = min(min_tree[i / 2], min_tree[i]);
		}
	}

	void Fill_Max_Tree()
	{
		for (int i = tree_size - 1; i > 0; i--)
		{
			max_tree[i / 2] = max(max_tree[i / 2], max_tree[i]);
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
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, K;

	cin >> N >> M;

	Segment_Tree* st = new Segment_Tree(N);

	for (int i = st->Get_Tree_Size() / 2; i < st->Get_Tree_Size() / 2 + N; i++)
	{
		int value;
		cin >> value;
		st->min_tree[i] = st->max_tree[i] = value;
	}

	st->Fill_Min_Tree();
	st->Fill_Max_Tree();

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b;

		cout << st->Get_Min_Of_Range(st->Get_Tree_Index(a), st->Get_Tree_Index(b)) << ' ' << st->Get_Max_Of_Range(st->Get_Tree_Index(a), st->Get_Tree_Index(b)) << '\n';
	}
}