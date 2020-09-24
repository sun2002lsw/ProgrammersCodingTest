#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetFirstNum(string& s)
{
	size_t beginIdx = 0;
	int mul = +1;

	if (s[0] == '-')
	{
		beginIdx = 1;
		mul = -1;
	}

	return mul * atoi(&s[beginIdx]);
}

string solution(string s) {
	vector<int> v;

	for (size_t endIdx; (endIdx = s.find(' ')) != string::npos; s.erase(0, endIdx + 1))
		v.push_back(GetFirstNum(s));
	v.push_back(GetFirstNum(s));

	sort(v.begin(), v.end());

	return to_string(v.front()) + " " + to_string(v.back());
}

int main()
{
	string s = "-1 -2 -3 -4";
	solution(s);

	return 0;
}