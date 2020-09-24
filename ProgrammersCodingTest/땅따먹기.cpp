#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

size_t N;
int cache[100000][4];

int GetBestLand(const vector<vector<int>>& land, size_t row, size_t col)
{
	if (row == N)
		return 0;
	
	int &curBest = cache[row][col];
	if (curBest != -1)
		return curBest;

	int nextBest = 0;
	for (size_t nextCol = 0; nextCol < 4; nextCol++)
		if (nextCol != col)
			nextBest = max(nextBest, GetBestLand(land, row + 1, nextCol));

	return curBest = land[row][col] + nextBest;
}

int solution(vector<vector<int>> land)
{
	N = land.size();
	memset(cache, -1, sizeof(cache));

	int answer = 0;
	for (size_t col = 0; col < 4; col++)
		answer = max(answer, GetBestLand(land, 0, col));

	return answer;
}
