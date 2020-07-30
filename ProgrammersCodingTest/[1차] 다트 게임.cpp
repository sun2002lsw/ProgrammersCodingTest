#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string dartResult) {
	vector<string> dartResultAry;
	for (const char c : dartResult)
		if (dartResultAry.empty() || isdigit(c) == 0 || isdigit(dartResultAry.back()[0]) == 0)
			dartResultAry.emplace_back(1, c);
		else
			dartResultAry.back().append(1, c);

	vector<int> numbers = { 0 };
	for (const string& s : dartResultAry)
		if (isdigit(s[0]) == 0)
			switch (s[0])
			{
			case 'S':
				break;
			case 'D':
				numbers.back() *= numbers.back();
				break;
			case 'T':
				numbers.back() *= numbers.back() * numbers.back();
				break;
			case '#':
				numbers.back() *= -1;
				break;
			case '*':
				numbers[numbers.size() - 1] *= 2;
				numbers[numbers.size() - 2] *= 2;
				break;
			default:
				return -1;
			}
		else
			numbers.push_back(atoi(s.c_str()));

	int answer = 0;
	for_each(numbers.begin(), numbers.end(), [&answer](int number) { answer += number; });
	return answer;
}

int main()
{
	string dartResult = "1D2S#10S";

	solution(dartResult);

	return 0;
}
