#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool IsDollExplode(stack<int>& basket, const int dollNum)
{
    if (basket.empty() || basket.top() != dollNum)
    {
        basket.push(dollNum);
        return false;
    }
    else
    {
        basket.pop();
        return true;
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<queue<int>> lineQueue;
    stack<int> basket;

    size_t boardSize = board.size();
    lineQueue.resize(boardSize + 1);

    for (size_t y = 0; y < boardSize; y++)
        for (size_t x = 0; x < boardSize; x++)
        {
            const int dollNum = board[y][x];
            if (dollNum != 0)
                lineQueue[x + 1].push(dollNum);
        }

    for (const int line : moves)
        if (lineQueue[line].empty() == false)
        {
            int dollNum = lineQueue[line].front();
            lineQueue[line].pop();

            if (IsDollExplode(basket, dollNum))
                answer += 2;
        }

    return answer;
}

int main()
{
    vector<vector<int>> board = { {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} };
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

    solution(board, moves);

    return 0;
}
