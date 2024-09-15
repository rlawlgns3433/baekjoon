#include <queue>
#include <unordered_set>

template <typename T>
void BFS(const T& element)
{
	std::queue<T> q;
	std::unordered_set<T> uSet;
	q.push(element);

	while (!q.empty())
	{
		T current = q.front();
		q.pop();

		uSet.insert(current);

		for (const T& adjacent: q.GetConnetedElements())
		{
			if (uSet.find(adjacent) == uSet.end())
			{
				q.push(adjacent);
				uSet.insert(adjacent);
			}
		}
	}
}