#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<vector<int>> pattern = { {}, { 1, 2, 3, 4, 5 }, { 2, 1, 2, 3, 2, 4, 2, 5 }, { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };
	vector<int> score = { 0, 0, 0, 0 };

	for (size_t i = 0; i < answers.size(); i++)
		for (int p = 1; p <= 3; p++)
			if (answers[i] == pattern[p][i % pattern[p].size()])
				score[p]++;

	int maxScore = *max_element(score.begin(), score.end());

	vector<int> answer;
	for (int p = 1; p <= 3; p++)
		if (score[p] == maxScore)
			answer.push_back(p);

	return answer;
}

int main()
{
	vector<int> answers1 = { 1,2,3,4,5 };
	answers1 = solution(answers1);

	vector<int> answers2 = { 1,3,2,4,2 };
	answers2 = solution(answers2);

	return 0;
}
