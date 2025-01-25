#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;


class StudentGrade
{
public:
	StudentGrade(string n, int k, int e, int m)
	{
		name = n;
		korean = k;
		english = e;
		math = m;
	}

	string name;
	int korean;
	int english;
	int math;
};

bool Compare(const StudentGrade& lhs, const StudentGrade& rhs)
{
	if (lhs.korean < rhs.korean)
		return false;
	else if (lhs.korean == rhs.korean)
	{
		if (lhs.english == rhs.english)
		{
			if (lhs.math == rhs.math)
				return lhs.name.compare(rhs.name) > 0 ? false : true;

			return lhs.math > rhs.math;
		}

		return lhs.english < rhs.english;
	}
	return true;
}

int main()
{
	int n;

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	string name;
	vector<StudentGrade> sg;
	int kor, eng, mat;
	for (int i = 0; i < n; ++i)
	{
		cin >> name >> kor >> eng >> mat;

		StudentGrade s(name, kor, eng, mat);
		sg.push_back(s);
	}

	sort(sg.begin(), sg.end(), Compare);

	for (int i = 0; i < n; ++i)
	{
		cout << sg[i].name << endl;
	}
}