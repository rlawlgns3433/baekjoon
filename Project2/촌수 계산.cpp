#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Person
{
public:
    int index;
    Person* parent = nullptr;
    vector<Person*> childs;

    Person(int i) : index(i) {}

    void SetParent(Person* p)
    {
        parent = p;
    }

    void SetChild(Person* p)
    {
        childs.push_back(p);
    }

    int FindRelation(Person* end)
    {
        set<Person*> visited;
        queue<pair<Person*, int>> q;

        q.push({ this, 0 });
        visited.insert(this);

        while (!q.empty())
        {
            pair<Person*, int> front = q.front();
            Person* person = front.first;
            int depth = front.second;
            q.pop();

            if (person == end)
                return depth;

            for (Person* child : person->childs)
            {
                if (visited.find(child) == visited.end())
                {
                    visited.insert(child);
                    q.push({ child, depth + 1 });
                }
            }

            if (person->parent != NULL && visited.find(person->parent) == visited.end())
            {
                visited.insert(person->parent);
                q.push({ person->parent, depth + 1 });
            }
        }

        return -1;
    }
};


int main()
{
    int n;
    cin >> n;

    vector<Person*> people(n + 1);

    for (int i = 0; i < people.size(); ++i)
    {
        people[i] = new Person(i + 1);
    }

    int start, end;
    cin >> start >> end;

    int m;
    cin >> m;
    int parent, child;
    for (int i = 0; i < m; ++i)
    {
        cin >> parent >> child;

        people[child - 1]->SetParent(people[parent - 1]);
        people[parent - 1]->SetChild(people[child - 1]);
    }

    cout << people[start - 1]->FindRelation(people[end - 1]);
}