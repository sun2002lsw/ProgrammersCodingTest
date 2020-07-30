#include <string>

using namespace std;

string solution(string s) {
	for (char& c : s)
		c = tolower(c);

	for (size_t wordCnt = 0, i = 0; i < s.size(); i++)
		if (s[i] == ' ')
			wordCnt = 0;
		else
		{
			if (wordCnt % 2 == 0)
				s[i] = toupper(s[i]);

			wordCnt++;
		}

	return s;
}
