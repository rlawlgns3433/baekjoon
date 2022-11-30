#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int B;
vector<int> obj;

// 통 채우기 알고리즘
// 이분탐색
int Approx_BinPacking(int n, int c)
{
    int l = 0, r = n;
    // 이분탐색으로 양 끝의 물건의 길이를 더하고, 이를 통의 길이와 비교
    while (l <= --r)
    {
        // 통의 길이가 더 길다면 왼쪽 물건은 한 칸 오른쪽으로
        // 오른쪽 물건은 한 칸 왼쪽으로 이동
        if (obj[l] + obj[r] <= c) l++;
        
        // 필요한 통 1개 추가
        B++;
    }
    // 총 필요한 통의 수 반환
    return B; 
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
    obj.resize(n);
    // 통에 들어갈 물건의 길이 입력
    for (int i = 0; i < n; i++)
    {
        cin >> obj[i];
    }
    // 길이의 오름차순으로 정렬
    sort(obj.begin(), obj.end());

    int answer = Approx_BinPacking(n, c);
    cout << answer;
}