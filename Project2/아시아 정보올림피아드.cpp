#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Student
{
public:
	Student(int _nation, int _snumber, int _score) : nation(_nation), snumber(_snumber), score(_score) {}
	int nation, snumber, score;
};

bool Compare(Student* lhs, Student* rhs)
{
	return lhs->score > rhs->score;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int nation, snumber, score;

	vector<Student*> students(n);
	unordered_map<int, int> umap;

	for (int i = 0; i < n; ++i)
	{
		cin >> nation >> snumber >> score;

		Student* student = new Student(nation, snumber, score);

		if (umap.find(nation) == umap.end())
			umap.insert(make_pair(nation, 0));

		students[i] = student;
	}

	sort(students.begin(), students.end(), Compare);

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (umap[students[i]->nation] == 2)
			continue;

		umap[students[i]->nation] += 1;
		cout << students[i]->nation << ' ' << students[i]->snumber << '\n';

		count++;
		if (count == 3)
			break;
	}
}