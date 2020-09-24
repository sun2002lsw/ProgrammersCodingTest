#include <string>

using namespace std;

bool solution(string s)
{
	int stack = 0;

	for (const char c : s)
		if (c == '(')
			stack++;
		else
			if (stack == 0)
				return false;
			else
				stack--;

	return stack == 0;
}
