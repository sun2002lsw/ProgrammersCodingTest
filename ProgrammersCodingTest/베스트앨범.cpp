#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct SongCmp;
using namespace std;
using playCntWithIdx = pair<int, int>;
using genreWithPlayCnt = pair<string, int>;
using topPlayCntWithIdx = priority_queue<playCntWithIdx, vector<playCntWithIdx>, SongCmp>;

bool cmp(const genreWithPlayCnt& lhs, const genreWithPlayCnt& rhs)
{
	return lhs.second > rhs.second;
}

struct SongCmp
{
	bool operator()(const playCntWithIdx& lhs, const playCntWithIdx& rhs)
	{
		if (lhs.first == rhs.first)
			return lhs.second > rhs.second;

		return lhs.first < rhs.first;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, topPlayCntWithIdx> topPlaysByGenre;
	unordered_map<string, int> playCntByGenre;

	for (int i = 0; i < genres.size(); i++)
	{
		const string& genre = genres[i];
		int playCnt = plays[i];

		topPlaysByGenre[genre].emplace(playCnt, i);
		playCntByGenre[genre] += playCnt;
	}

	vector<genreWithPlayCnt> genresPlayCnt(playCntByGenre.begin(), playCntByGenre.end());
	sort(genresPlayCnt.begin(), genresPlayCnt.end(), cmp);

	vector<int> answer;
	for (const auto& genrePlayCnt : genresPlayCnt)
	{
		const string& genre = genrePlayCnt.first;
		
		int firstTopSongIdx = topPlaysByGenre[genre].top().second;
		answer.push_back(firstTopSongIdx);
		topPlaysByGenre[genre].pop();

		if (!topPlaysByGenre[genre].empty())
		{
			int secondTopSongIdx = topPlaysByGenre[genre].top().second;
			answer.push_back(secondTopSongIdx);
		}
	}

	return answer;
}
