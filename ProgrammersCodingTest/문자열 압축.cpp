#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int NumDigits(int num)
{
	int counter = 0;
	for (; num > 0; num /= 10, counter++);
	return counter;
}

int GetCompressSize(size_t charSize, const string& str)
{
	stack<pair<string, int>> subStrStack;

	for (size_t i = 0; i < str.size(); i += charSize)
	{
		string subStr = str.substr(i, charSize);

		if (!subStrStack.empty() && subStrStack.top().first == subStr)
			subStrStack.top().second++;
		else
			subStrStack.push(make_pair(subStr, 1));
	}

	int compressSize = subStrStack.size() * charSize;
	for (; !subStrStack.empty(); subStrStack.pop())
	{
		int numDigits = 0;
		if (subStrStack.top().second > 1)
			numDigits = NumDigits(subStrStack.top().second);

		compressSize += numDigits;
	}

	return compressSize;
}

int solution(string s) {
	int answer = s.size();

	for (size_t charSize = 1; charSize <= s.size() / 2; charSize++)
	{
		size_t remainCharSize = s.size() % charSize;
		size_t endIdx = s.size() - remainCharSize;

		int compressSize = GetCompressSize(charSize, s.substr(0, endIdx)) + remainCharSize;

		answer = min(answer, compressSize);
	}

	return answer;
}

int main()
{
	string s = "abcabcdede";
	int answer = solution(s);

	return 0;
}
