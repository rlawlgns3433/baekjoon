#include <iostream>
#include <set>
using namespace std;

multiset<int> ms;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int testcase, n;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        ms.clear();
        cin >> n;
        char input_c; int input_i;
        for (int j = 0; j < n; j++) {
            cin >> input_c >> input_i;
            if (input_c == 'I')
                ms.emplace(input_i);
            else {
                if (ms.empty()) continue;
                if (input_i == 1) {
                    int val = *ms.rbegin();
                    int ele_count = ms.count(val);
                    ms.erase(val);
                    if (ele_count > 1) {
                        for (int i = 1; i < ele_count; i++)
                            ms.emplace(val);
                    }
                }
                else ms.erase(ms.begin());
            }
        }
        if (ms.empty())
            cout << "EMPTY\n";
        else cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
    }
}

