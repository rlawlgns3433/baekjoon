#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp_n; cin >> temp_n;
        a.emplace_back(temp_n);
    }
    sort(a.begin(), a.end());

    if (a.size() == 1) {
        cout << pow(a[0], 2);
    }
    else {
        cout << *a.begin() * *(a.end() - 1);
    }
}