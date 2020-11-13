#include <set>
#include <vector>
using namespace std;

struct Player
{
public:
	auto AddWinner(Player* player)
	{
		winnerSet.insert(player);
	}

	auto AddLoser(Player* player)
	{
		loserSet.insert(player);
	}

	void MergeWinnerSet()
	{
		if (winnerSetMerged)
			return;

		for (const auto winner : winnerSet)
		{
			winner->MergeWinnerSet();
			winnerSet.insert(winner->winnerSet.begin(), winner->winnerSet.end());
		}

		winnerSetMerged = true;
	}

	void MergeLoserSet()
	{
		if (loserSetMerged)
			return;

		for (const auto loser : loserSet)
		{
			loser->MergeLoserSet();
			loserSet.insert(loser->loserSet.begin(), loser->loserSet.end());
		}

		loserSetMerged = true;
	}

	size_t GetOpponentCnt()
	{
		return winnerSet.size() + loserSet.size();
	}

private:
	set<Player*> winnerSet;
	set<Player*>  loserSet;

	bool winnerSetMerged = false;
	bool  loserSetMerged = false;
};

int solution(int n, vector<vector<int>> results) {
	vector<Player> playerVec(n);
	
	for (const auto& result : results)
	{
		Player* winner = &playerVec[result[0] - 1];
		Player* loser  = &playerVec[result[1] - 1];

		winner->AddLoser(loser);
		loser->AddWinner(winner);
	}

	for (auto& player : playerVec)
	{
		player.MergeWinnerSet();
		player.MergeLoserSet();
	}

	int answer = 0;
	for (auto& player : playerVec)
		if (player.GetOpponentCnt() + 1 == n)
			answer++;

	return answer;
}

int main()
{
	int n = 6;
	vector<vector<int>> results = { {1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 5}, {3, 6}, {2, 3}, {3, 4} };

	return solution(n, results);
}
