#include <string>
#include <math.h>

using namespace std;

char Get124(int& n, int digitIdx)
{
	int divisor = pow(3, digitIdx);
	int remainder = n % divisor;
	if (remainder == 0)
		remainder = divisor;

	n -= remainder;

	if (remainder <= 1 * divisor / 3)
		return '1';
	if (remainder <= 2 * divisor / 3)
		return '2';
	if (remainder <= 3 * divisor / 3)
		return '4';
}

string solution(int n) {
	string answer;
	for (int digitIdx = 1; n > 0; digitIdx++)
		answer.insert(0, 1, Get124(n, digitIdx));

	return answer;
}

int main()
{
	solution(500000000);

	return 0;
}
