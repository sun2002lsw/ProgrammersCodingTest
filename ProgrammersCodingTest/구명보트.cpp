#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	sort(people.begin(), people.end());
	deque<int> people_(people.begin(), people.end());

	int answer = 0;
	while (true)
	{
		if (people_.size() < 2)
		{
			answer += people_.size();
			break;
		}

		int light = people_.front();
		people_.pop_front();
		answer++;

		while (!people_.empty() && light + people_.back() > limit)
		{
			answer++;
			people_.pop_back();
		}

		if (!people_.empty())
			people_.pop_back();
	}

	return answer;
}
