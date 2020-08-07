#include <string>

using namespace std;

string solution(string number, int k) {
	for (size_t i = 0; i < number.size() && k > 0;)
		if (number[i] < number[i + 1])
		{
			number.erase(i, 1);
			k--;
			i -= (i > 0);
		}
		else
			i++;

	number.erase(number.size() - k, k);
	return number;
}

int main()
{
	string answer = solution("987654", 3);

	return 0;
}
