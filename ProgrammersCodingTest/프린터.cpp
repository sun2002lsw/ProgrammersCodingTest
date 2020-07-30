#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

queue<pair<int, bool>> printQueue;
queue<int> priorityQueue;

void FindNextPrint()
{
	int topPriority = priorityQueue.front();
	priorityQueue.pop();

	while (printQueue.front().first != topPriority)
	{
		printQueue.push(printQueue.front());
		printQueue.pop();
	}
}

int solution(vector<int> priorities, int location) {
	for (int i = 0; i < priorities.size(); i++)
		printQueue.emplace(priorities[i], i == location);

	sort(priorities.begin(), priorities.end(), greater<int>());
	for (const int priority : priorities)
		priorityQueue.push(priority);

	for (int answer = 1; true; answer++)
	{
		FindNextPrint();

		if (printQueue.front().second == true)
			return answer;
		else
			printQueue.pop();
	}
}

int main()
{
	vector<int> priorities = { 2, 1, 3, 2 };
	int location = 2;

	solution(priorities, location);

	return 0;
}
