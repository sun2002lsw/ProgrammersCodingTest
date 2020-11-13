#include <vector>
#include <cstring>
using namespace std;

int cache[102][102];

int solution(int m, int n, vector<vector<int>> puddles) {
	for (int i = 1; i <= m; i++)
		memset(cache[i], -1, sizeof(cache[i]));
	for (int i = 1; i <= m; i++)
		cache[i][n + 1] = 0;
	for (int j = 1; j <= n; j++)
		cache[m + 1][j] = 0;
	
	cache[m][n] = 1;
	for (const auto& puddle : puddles)
		cache[puddle[0]][puddle[1]] = 0;

	for (int i = m; i > 0; i--)
		for (int j = n; j > 0; j--)
			if (i != m || j != n)
				if (cache[i][j] == -1)
					cache[i][j] = (cache[i + 1][j] + cache[i][j + 1]) % 1000000007;

	return cache[1][1];
}

int main()
{
	int m = 4;
	int n = 3;
	vector<vector<int>> puddles = { {4, 3} };

	return solution(m, n, puddles);
}
