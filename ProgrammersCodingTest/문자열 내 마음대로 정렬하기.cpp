#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool cmp(string lhs, string rhs, int n)
{
	if (lhs[n] == rhs[n])
		return lhs < rhs;
	else
		return lhs[n] < rhs[n];
}

vector<string> solution(vector<string> strings, int n) {
	auto pred = bind(cmp, placeholders::_1, placeholders::_2, n);
	sort(strings.begin(), strings.end(), pred);

	return strings;
}

int main()
{
	vector<string> strings = { "sun", "bed", "car" };
	solution(strings, 1);

	return 0;
}