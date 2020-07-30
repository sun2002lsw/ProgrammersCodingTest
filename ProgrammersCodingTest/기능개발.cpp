#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	int maxRemainDay = 0;
	vector<int> answer;

	for (size_t i = 0; i < progresses.size(); i++)
	{
		int remainProgress = 100 - progresses[i];
		int remainDay = ceil((double)remainProgress / (double)speeds[i]);

		if (answer.empty() || maxRemainDay < remainDay)
			answer.push_back(1);
		else
			++answer.back();

		maxRemainDay = max(maxRemainDay, remainDay);
	}

	return answer;
}

int main()
{
	vector<int> progresses = { 93,30,55 };
	vector<int> speeds = { 1,30,5 };
	
	solution(progresses, speeds);

	return 0;
}
