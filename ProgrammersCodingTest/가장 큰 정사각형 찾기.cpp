#include <vector>
#include <algorithm>

using namespace std;

size_t xLimit, yLimit;

int GetBoardVal(const vector<vector<int>>& board, size_t x, size_t y)
{
	if (x < 0 || xLimit <= x)
		return 0;
	if (y < 0 || yLimit <= y)
		return 0;

	return board[x][y];
}

int GetLargestSquareWidth(vector<vector<int>>& board, size_t x, size_t y)
{
	if (board[x][y] == 0)
		return 0;

	const int square1 = GetBoardVal(board, x - 1, y);
	const int square2 = GetBoardVal(board, x, y - 1);
	const int square3 = GetBoardVal(board, x - 1, y - 1);

	return board[x][y] = min(square1, min(square2, square3)) + 1;
}

int solution(vector<vector<int>> board)
{
	xLimit = board.size();
	yLimit = board[0].size();

	int largestWidth = 0;
	for (size_t x = 0; x < board.size(); x++)
		for (size_t y = 0; y < board[x].size(); y++)
			largestWidth = max(largestWidth, GetLargestSquareWidth(board, x, y));

	return largestWidth * largestWidth;
}

int main()
{
	vector<vector<int>> board = { {0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0} };
	int answer = solution(board);

	return 0;
}
