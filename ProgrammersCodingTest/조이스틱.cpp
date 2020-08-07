#include <string>
#include <cmath>
#include <deque>

using namespace std;

size_t nameSize;
size_t curPos = 0;
deque<size_t> targetIdx;

int MoveUpDown(char target)
{
	int moveCnt = target - 'A';
	if (moveCnt > 13)
		moveCnt = 26 - moveCnt;

	return moveCnt;
}

int MoveLeftRight()
{
	int rightDistance = targetIdx.front() - curPos;
	if (rightDistance < 0)
		rightDistance = 999;

	int leftDistance = curPos - targetIdx.back();
	if (leftDistance < 0)
		leftDistance += nameSize;

	if (leftDistance < rightDistance)
	{
		curPos = targetIdx.back();
		targetIdx.pop_back();

		return leftDistance;
	} 
	else
	{
		curPos = targetIdx.front();
		targetIdx.pop_front();

		return rightDistance;
	}
}

int solution(string name) {
	nameSize = name.size();

	for (size_t i = 0; i < name.size(); i++)
		if (name[i] != 'A')
			targetIdx.push_back(i);

	int answer = 0;
	while (!targetIdx.empty())
	{
		answer += MoveLeftRight();
		answer += MoveUpDown(name[curPos]);
	}

	return answer;
}

int main()
{
	string name = "JAN";
	int answer = solution(name);

	return 0;
}