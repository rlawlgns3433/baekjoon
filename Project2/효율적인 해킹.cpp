/// <summary>
/// 1325 ȿ������ ��ŷ
/// </summary>

#include <iostream> // input output stream : ����� �Լ����� �ִ� ��� ����
#include <algorithm> // algorithm : ������ �˰��� �Լ����� ����ִ� ��� ����
#include <vector> // vector : vector �����̳ʸ� ����ϱ� ���� ��� ����
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)) // ���� ������� ���� ���
using namespace std; // standard namespace : �⺻���� ������Ʈ���� ����ִ� namespace


/// <summary>
/// N : ��ǻ���� ��
/// M : �ŷ� ������ ��
/// current_cnt : ������� ��ŷ�� �� �ִ� ��ǻ���� ��
/// max_cnt : ��ŷ�� �� �ִ� ��ǻ���� �ִ밪
/// h_map : �ŷ��ϴ� ���踦 ��Ÿ���� �� src�� dst�� �ŷ��ϸ� h_map[dst]�� src�� ����
/// visited : ��ǻ�͸� �̹� ��ŷ�ߴ����� ��Ÿ���� �迭
/// answer : ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ(��)
/// </summary>
int N, M, current_cnt, max_cnt = -1;
vector<int> h_map[10001];
bool visited[10001];
vector<int> answer;

/// <summary>
/// ���̿켱 Ž���� �ϴ� �Լ�
/// </summary>
/// <param name="start"></param>
void dfs(int start)
{
	visited[start] = true;
	current_cnt++;

	// ���� ��ŷ�� ��ǻ�͸� �ŷ��ϴ� ����ŭ �ݺ�
	for (int i = 0; i < h_map[start].size(); i++)
	{
		// ���� ��ǻ�͸� �ŷ��ϴ� ��ǻ�͸� ���� �湮(��ŷ)���� �ʾҴٸ�
		if (!visited[h_map[start][i]])
			// ���̿켱 Ž������ �� ��ǻ�͸� �ŷ��ϴ� ��ǻ�͸� �湮(��ŷ)
			dfs(h_map[start][i]);
	}
}

// �湮 ����� �ʱ�ȭ��
void reset_visited()
{
	for (int i = 0; i <= N; i++)
	{
		visited[i] = false;
	}
}

int main()
{
	cin >> N >> M;


	for (int i = 0; i < M; i++)
	{
		/// <summary>
		/// src�� dst�� �ŷ���
		/// </summary>
		int src, dst; 
		cin >> src >> dst;
		// dst�� �ŷ��ϴ� src�� ����
		h_map[dst].push_back(src);
	}

	// ��� ��ǻ�͸� ���鼭 ��ŷ�� �� �ִ� ��ǻ���� �ִ� ���� ����
	for (int i = 1; i <= N; i++)
	{
		current_cnt = 0; // ��ǻ�͸� ���������� ��ŷ�� ������ ��ŷ�� ��ǻ�� ���� �ʱ�ȭ
		reset_visited(); // ��ǻ�͸� ���������� ��ŷ�� ������ ��ŷ�� ��ǻ�͵��� �ʱ�ȭ

		dfs(i); // ���̿켱Ž������ ���� ��ǻ�ͷ� ��ŷ�� �� �ִ� ��ǻ���� ���� ����

		// ��ŷ�� �� �ִ� �ִ� ���ں��� ũ��
		if (max_cnt < current_cnt)
		{
			answer.clear(); // �������� �ִ� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ�� ��ȣ�� �ʱ�ȭ
			answer.push_back(i); // ���� ��ǻ���� ��ȣ�� ����
			max_cnt = current_cnt; // �ִ� ���� ���� ���� ����
		}
		// ��ŷ�� �� �ִ� �ִ� ���ڰ� �����ϸ�
		else if (max_cnt == current_cnt)
		{
			answer.push_back(i); // ���� ��ǻ�� ��ȣ�� �߰��� ����
		}
	}

	// ������ ������������ ����
	sort(answer.begin(), answer.end());

	for (auto& e : answer)
		cout << e << ' '; // ���� ���

	return 0;
}
