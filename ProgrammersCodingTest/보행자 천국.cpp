#include <vector>
using namespace std;

vector<vector<int>> cityMap;
int M, N, MOD = 20170805;
int cache[2][500][500];

int GetAnswer(int x, int y, char direction)
{
	if (x == M || y == N)
		return 0;
	if (x == M - 1 && y == N - 1)
		return 1;

	int& cases = cache[direction == 'x'][x][y];
	if (cases != -1)
		return cases;

	switch (cityMap[x][y])
	{
	case 1: // 자동차 통행 금지
		return cases = 0;
	case 0: // 자동차가 자유롭게 지나감
		return cases = (GetAnswer(x + 1, y, 'x') + GetAnswer(x, y + 1, 'y')) % MOD;
	case 2: // 직진만 가능
		return cases = (direction == 'x') ? GetAnswer(x + 1, y, 'x') : GetAnswer(x, y + 1, 'y');
	}
}

int solution(int m, int n, vector<vector<int>> city_map) {
	cityMap = move(city_map);
	M = m;
	N = n;

	for (int character = 0; character < 2; character++)
		for (int i = 0; i < 500; i++)
			for (int j = 0; j < 500; j++)
				cache[character][i][j] = -1;

	return (GetAnswer(1, 0, 'x') + GetAnswer(0, 1, 'y')) % MOD;
}
