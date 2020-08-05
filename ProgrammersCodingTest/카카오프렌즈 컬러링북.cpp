#include <vector>
#include <algorithm>
using namespace std;

int xLimit, yLimit;
vector<vector<int>> picture_;

int findAreaSize(int x, int y, int num)
{
	if (x < 0 || x == xLimit)
		return 0;
	if (y < 0 || y == yLimit)
		return 0;
	if (picture_[x][y] == 0)
		return 0;
	if (picture_[x][y] != num)
		return 0;

	int size = 1;
	picture_[x][y] = 0;

	size += findAreaSize(x - 1, y, num);
	size += findAreaSize(x + 1, y, num);
	size += findAreaSize(x, y - 1, num);
	size += findAreaSize(x, y + 1, num);

	return size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	xLimit = picture.size();
	yLimit = picture[0].size();
	picture_ = std::move(picture);

	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int x = 0; x < xLimit; x++)
		for (int y = 0; y < yLimit; y++)
			if (picture_[x][y]) {
				number_of_area++;
				max_size_of_one_area = max(max_size_of_one_area, findAreaSize(x, y, picture_[x][y]));
			}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
