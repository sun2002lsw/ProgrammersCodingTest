#include <list>
#include <cmath>
#include <vector>
using namespace std;

list<pair<int, int>> bigSquare;
list<pair<int, int>> smallSquare;

void makeSquareList(int blockCnt, list<pair<int, int>>& square)
{
	const int maxHeight = (int)sqrt(blockCnt);

	for (int height = 1; height <= maxHeight; height++)
		if (blockCnt % height == 0)
			square.push_back(make_pair(blockCnt / height, height));
}

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	makeSquareList(brown + yellow, bigSquare);
	makeSquareList(yellow, smallSquare);

	for (const auto& big : bigSquare)
		for (const auto& small : smallSquare)
			if (big.first > small.first && big.second > small.second)
				if ((big.first - small.first) % 2 == 0 && (big.second - small.second) % 2 == 0)
				{
					answer.push_back(big.first);
					answer.push_back(big.second);

					return answer;
				}
}

int main()
{
	const int brown = 24;
	const int yellow = 24;

	solution(brown, yellow);

	return 0;
}