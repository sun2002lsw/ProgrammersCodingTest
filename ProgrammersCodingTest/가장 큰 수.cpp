#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int lhs, int rhs) {
	return to_string(lhs) + to_string(rhs) > to_string(rhs) + to_string(lhs);
}

string solution(vector<int> numbers) {
	sort(numbers.begin(), numbers.end(), cmp);

	string answer;
	for (const int number : numbers)
		answer.append(to_string(number));

	if (answer[0] == '0')
		answer.erase(1);

	return answer;
}

int main()
{
	vector<int> numbers = { 770, 7 };

	string answer = solution(numbers);

	return 0;
}
