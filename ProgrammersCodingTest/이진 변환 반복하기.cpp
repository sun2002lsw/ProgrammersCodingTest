#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string GetBinaryStr(size_t num)
{
	string s;
	while (num > 0)
	{
		s.push_back('0' + num % 2);
		num /= 2;
	}

	reverse(s.begin(), s.end());
	return s;
}

vector<int> solution(string s) {
	int loopCnt = 0, zeroCnt = 0;

	while (s != "1")
	{
		zeroCnt += (int)count(s.begin(), s.end(), '0');

		s.erase(remove(s.begin(), s.end(), '0'), s.end());
		s = GetBinaryStr(s.size());

		loopCnt++;
	}

	vector<int> answer = { loopCnt , zeroCnt };
	return answer;
}

int main()
{
	string s = "110010101001";
	solution(s);

	return 0;
}