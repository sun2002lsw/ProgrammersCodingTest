#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (const auto& command : commands)
	{
		const int startIdx = command[0] - 1;
		const int endIdx = command[1];
		const int k = command[2] - 1;

		const auto startIter = array.begin() + startIdx;
		const auto endIter = array.begin() + endIdx;

		vector<int> arrayCopy(startIter, endIter);
		sort(arrayCopy.begin(), arrayCopy.end());

		answer.push_back(arrayCopy[k]);
	}

	return answer;
}

int main()
{
	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };

	solution(std::move(array), std::move(commands));

	return 0;
}
