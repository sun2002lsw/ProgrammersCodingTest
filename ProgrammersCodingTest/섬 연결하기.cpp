#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	Edge(int u, int v, int c) : point(make_pair(u, v)), cost(c) {}

	pair<int, int> point;
	int cost;
};

bool EdgeCmp(const Edge& lhs, const Edge& rhs)
{
	return lhs.cost < rhs.cost;
}

class DisjointSet
{
public:
	DisjointSet(size_t size)
	{
		for (int i = 0; i < size; i++)
			root.push_back(i);
	}

	int Find(int u)
	{
		if (u == root[u])
			return u;

		return root[u] = Find(root[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);
		if (u == v)
			return;

		root[u] = v;
	}
	
private:
	vector<int> root;
};

int solution(int n, vector<vector<int>> costs) {
	vector<Edge> edgeVec;
	DisjointSet disjointSet(n);

	for (size_t i = 0; i < costs.size(); i++)
		edgeVec.emplace_back(costs[i][0], costs[i][1], costs[i][2]);
	sort(edgeVec.begin(), edgeVec.end(), EdgeCmp);

	int answer = 0;
	for (const Edge& e : edgeVec)
	{
		int u = e.point.first;
		int v = e.point.second;
		int cost = e.cost;

		if (disjointSet.Find(u) != disjointSet.Find(v))
		{
			disjointSet.Merge(u, v);
			answer += cost;
		}
	}

	return answer;
}
