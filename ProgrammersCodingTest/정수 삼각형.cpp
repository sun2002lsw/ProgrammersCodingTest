#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[500][500];

int GetAnswer(const vector<vector<int>>& triangle, int line, int idx)
{
	if (line == (int)triangle.size())
		return 0;

	int& ans = cache[line][idx];
	if (ans != -1)
		return ans;

	int candid1 = GetAnswer(triangle, line + 1, idx);
	int candid2 = GetAnswer(triangle, line + 1, idx + 1);

	return ans = triangle[line][idx] + max(candid1, candid2);
}

int solution(vector<vector<int>> triangle) {
	for (int i = 0; i < triangle.size(); i++)
		memset(cache[i], -1, sizeof(cache[i]));

	return GetAnswer(triangle, 0, 0);
}
