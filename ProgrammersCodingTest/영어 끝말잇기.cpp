#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	unordered_set<string> usedWords = { words[0] };
	vector<int> answer = { 0, 0 };

	for (int i = 1; i < words.size(); i++)
		if (words[i].size() == 1 || words[i - 1].back() != words[i].front() || !usedWords.insert(words[i]).second)
		{
			answer[0] = 1 + i % n;
			answer[1] = 1 + i / n;
			break;
		}

	return answer;
}

int main()
{
	vector<string> words = { "land", "dream", "mom", "mom", "ror" };
	solution(2, words);
}
