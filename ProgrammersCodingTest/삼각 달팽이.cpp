#include <vector>
using namespace std;
enum class Direction { UP, DOWN, RIGHT };

vector<vector<int>> pyramid;
size_t curRow = 0, curCol = 0;
Direction dir = Direction::DOWN;
int number = 1;

bool Move()
{
	// change direction if need
	switch (dir)
	{
	case Direction::UP:
		if (pyramid[curRow - 1][curCol - 1] != 0)
			dir = Direction::DOWN;
		break;
	case Direction::DOWN:
		if (curRow + 1 == pyramid.size() || pyramid[curRow + 1][curCol] != 0)
			dir = Direction::RIGHT;
		break;
	case Direction::RIGHT:
		if (curCol + 1 == pyramid[curRow].size() || pyramid[curRow][curCol + 1] != 0)
			dir = Direction::UP;
		break;
	default:
		break;
	}

	// move to next
	switch (dir)
	{
	case Direction::UP:
		curRow--;
		curCol--;
		break;
	case Direction::DOWN:
		curRow++;
		break;
	case Direction::RIGHT:
		curCol++;
		break;
	default:
		break;
	}

	// check validation
	return pyramid[curRow][curCol] == 0;
}

void MakePyramid(int n)
{
	pyramid.resize(n);
	for (size_t row = 0; row < n; row++)
		pyramid[row].resize(row + 1);

	do {
		pyramid[curRow][curCol] = number++;
	} 
	while (Move());
}

vector<int> solution(int n) {
	MakePyramid(n);

	vector<int> answer;
	for (size_t row = 0; row < n; row++)
		for (size_t col = 0; col < row + 1; col++)
			answer.push_back(pyramid[row][col]);

	return answer;
}
