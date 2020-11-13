#include <set>
#include <vector>
using namespace std;

class DisjointSet
{
public:
	DisjointSet(int size)
	{
		for (int i = 0; i < size; i++)
			parent.push_back(i);
	}

	int find(int u)
	{
		if (u == parent[u])
			return u;

		return parent[u] = find(parent[u]);
	}

	void Merge(int u, int v)
	{
		u = find(u);
		v = find(v);

		if (u == v)
			return;
		else
			parent[u] = v;
	}

private:
	vector<int> parent;
};

int solution(int n, vector<vector<int>> computers) {
	DisjointSet disjointSet(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (computers[i][j])
				disjointSet.Merge(i, j);

	set<int> nodeSet;
	for (int i = 0; i < n; i++)
		nodeSet.insert(disjointSet.find(i));

	return (int)nodeSet.size();
}
