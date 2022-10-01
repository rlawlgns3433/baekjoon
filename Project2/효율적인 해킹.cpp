/// <summary>
/// 1325 효율적인 해킹
/// </summary>

#include <iostream> // input output stream : 입출력 함수들이 있는 헤더 파일
#include <algorithm> // algorithm : 유용한 알고리즘 함수들이 들어있는 헤더 파일
#include <vector> // vector : vector 컨테이너를 사용하기 위한 헤더 파일
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)) // 빠른 입출력을 위해 사용
using namespace std; // standard namespace : 기본적인 오브젝트들이 담겨있는 namespace


/// <summary>
/// N : 컴퓨터의 수
/// M : 신뢰 관계의 수
/// current_cnt : 현재까지 해킹할 수 있는 컴퓨터의 수
/// max_cnt : 해킹할 수 있는 컴퓨터의 최대값
/// h_map : 신뢰하는 관계를 나타내는 맵 src가 dst를 신뢰하면 h_map[dst]에 src를 삽입
/// visited : 컴퓨터를 이미 해킹했는지를 나타내는 배열
/// answer : 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호(들)
/// </summary>
int N, M, current_cnt, max_cnt = -1;
vector<int> h_map[10001];
bool visited[10001];
vector<int> answer;

/// <summary>
/// 깊이우선 탐색을 하는 함수
/// </summary>
/// <param name="start"></param>
void dfs(int start)
{
	visited[start] = true;
	current_cnt++;

	// 현재 해킹한 컴퓨터를 신뢰하는 수만큼 반복
	for (int i = 0; i < h_map[start].size(); i++)
	{
		// 현재 컴퓨터를 신뢰하는 컴퓨터를 아직 방문(해킹)하지 않았다면
		if (!visited[h_map[start][i]])
			// 깊이우선 탐색으로 이 컴퓨터를 신뢰하는 컴퓨터를 방문(해킹)
			dfs(h_map[start][i]);
	}
}

// 방문 목록을 초기화함
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
		/// src가 dst를 신뢰함
		/// </summary>
		int src, dst; 
		cin >> src >> dst;
		// dst를 신뢰하는 src를 모음
		h_map[dst].push_back(src);
	}

	// 모든 컴퓨터를 돌면서 해킹할 수 있는 컴퓨터의 최대 수를 구함
	for (int i = 1; i <= N; i++)
	{
		current_cnt = 0; // 컴퓨터를 순차적으로 해킹할 때마다 해킹한 컴퓨터 수를 초기화
		reset_visited(); // 컴퓨터를 순차적으로 해킹할 때마다 해킹한 컴퓨터들을 초기화

		dfs(i); // 깊이우선탐색으로 현재 컴퓨터로 해킹할 수 있는 컴퓨터의 수를 구함

		// 해킹할 수 있는 최대 숫자보다 크면
		if (max_cnt < current_cnt)
		{
			answer.clear(); // 이전까지 최대 수의 컴퓨터를 해킹할 수 있는 컴퓨터 번호를 초기화
			answer.push_back(i); // 현재 컴퓨터의 번호를 저장
			max_cnt = current_cnt; // 최대 수를 현재 수로 저장
		}
		// 해킹할 수 있는 최대 숫자가 동일하면
		else if (max_cnt == current_cnt)
		{
			answer.push_back(i); // 현재 컴퓨터 번호를 추가로 저장
		}
	}

	// 정답을 오름차순으로 정렬
	sort(answer.begin(), answer.end());

	for (auto& e : answer)
		cout << e << ' '; // 정답 출력

	return 0;
}
