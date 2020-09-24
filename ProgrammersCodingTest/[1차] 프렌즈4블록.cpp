#include <string>
#include <vector>

using namespace std;

int GetBlankCnt(const int m, const int n, const vector<string>& board)
{
	int blankCnt = 0;
	for (int row = 0; row < m; row++)
		for (int col = 0; col < n; col++)
			if (board[row][col] == ' ')
				blankCnt++;

	return blankCnt;
}

bool IsPangPoint(const int row, const int col, const vector<string>& board)
{
	if (board[row][col] == ' ')
		return false;
	if (board[row][col] != board[row + 1][col])
		return false;
	if (board[row][col] != board[row][col + 1])
		return false;
	if (board[row][col] != board[row + 1][col + 1])
		return false;
	
	return true;
}

void PangPang(const int row, const int col, vector<string>& board)
{
	board[row][col] = board[row + 1][col] = board[row][col + 1] = board[row + 1][col + 1] = ' ';
}

int PangCnt(const int m, const int n, vector<string>& board)
{
	int blankCnt = GetBlankCnt(m, n, board);

	vector<string> boardCopy = board;
	for (int row = 0; row < m - 1; row++)
		for (int col = 0; col < n - 1; col++)
			if (IsPangPoint(row, col, board))
				PangPang(row, col, boardCopy);
	board = boardCopy;

	return GetBlankCnt(m, n, board) - blankCnt;
}

void FallDown(const int m, const int n, vector<string>& board)
{
	for (int row = m - 1; row > 0; row--)
		for (int col = 0; col < n; col++)
			if (board[row][col] == ' ')
				for (int row2 = row - 1; row2 >= 0; row2--)
					if (board[row2][col] != ' ')
					{
						swap(board[row][col], board[row2][col]);
						break;
					}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	for (int pangCnt; pangCnt = PangCnt(m, n, board); FallDown(m, n, board))
		answer += pangCnt;

	return answer;
}

int main()
{
	int m = 6, n = 6;
	vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
	
	solution(m, n, board);

	return 0;
}
