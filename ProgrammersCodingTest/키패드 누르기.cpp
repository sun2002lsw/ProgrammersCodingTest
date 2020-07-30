#include <string>
#include <vector>

using namespace std;

struct pos
{
	pos(int a = 0, int b = 0) : x(a), y(b) {}

	int x, y;
};

vector<pos> numberPos;

void GetNumberPos()
{
	numberPos.resize(12, pos());

	numberPos[0] = pos(1, 3);
	for (int num = 1; num < 10; num++)
		numberPos[num] = pos((num - 1) % 3, (num - 1) / 3);

	// *, #
	numberPos[10] = pos(0, 3);
	numberPos[11] = pos(2, 3);
}

int GetDistance(const int handKey, const int targetKey)
{
	int x1 = numberPos[handKey].x;
	int y1 = numberPos[handKey].y;

	int x2 = numberPos[targetKey].x;
	int y2 = numberPos[targetKey].y;

	return abs(x1 - x2) + abs(y1 - y2);
}

int leftHand = 10, rightHand = 11;

char PressButton(const int number, const string& hand)
{
	if (number == 1 || number == 4 || number == 7)
	{
		leftHand = number;
		return 'L';
	}
	else if (number == 3 || number == 6 || number == 9)
	{
		rightHand = number;
		return 'R';
	}
	else
	{
		int leftDistance = GetDistance(leftHand, number);
		int rightDistance = GetDistance(rightHand, number);

		if (leftDistance < rightDistance)
		{
			leftHand = number;
			return 'L';
		}
		else if (leftDistance > rightDistance)
		{
			rightHand = number;
			return 'R';
		}
		else
			if (hand == "left")
			{
				leftHand = number;
				return 'L';
			}
			else
			{
				rightHand = number;
				return 'R';
			}
	}
}

string solution(vector<int> numbers, string hand) {
	GetNumberPos();

	string answer;
	for (const int number : numbers)
		answer.push_back(PressButton(number, hand));

	return answer;
}

int main()
{
	vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
	string hand = "right";

	solution(numbers, hand);

	return 0;
}
