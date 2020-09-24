#include <list>
using namespace std;

int solution(int n) {
	list<int> numList = { 0 };
	int sum = 0;
	int answer = 0;

	while (numList.empty() == false)
	{
		if (sum < n)
		{
			sum += numList.back() + 1;
			numList.push_back(numList.back() + 1);
		}
		else if (sum > n)
		{
			sum -= numList.front();
			numList.pop_front();
		}
		else // sum == n
		{
			answer++;

			sum += numList.back() + 1;
			numList.push_back(numList.back() + 1);

			sum -= numList.front();
			numList.pop_front();
		}
	}

	return answer;
}
