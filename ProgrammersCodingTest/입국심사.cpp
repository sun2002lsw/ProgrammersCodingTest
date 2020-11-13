#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());

	long long minTime = n / times.size() * times.front();
	long long maxTime = n / times.size() * times.back();

	while (minTime < maxTime)
	{
		long long timeLimit = (minTime + maxTime) / 2;

		long long remainPerson = n;
		for (int time : times)
			remainPerson -= timeLimit / time;

		if (remainPerson > 0)
			minTime = timeLimit + 1;
		else
			maxTime = timeLimit;
	}

	return minTime;
}

int main()
{
	int n = 6;
	vector<int> times = { 7, 10 };

	return solution(n, times);
}
