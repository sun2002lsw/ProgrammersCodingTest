#include <string>

using namespace std;

string solution(string s, int n) {
	for (char& c : s)
		if (c != ' ')
		{
			char firstChar = islower(c) ? 'a' : 'A';
			char lastChar  = islower(c) ? 'z' : 'Z';

			int alphabetIdx = c + n;
			if (alphabetIdx > lastChar)
			{
				alphabetIdx = (alphabetIdx - lastChar) % 26;

				if (alphabetIdx == 0)
					alphabetIdx = lastChar;
				else
					alphabetIdx += firstChar - 1;
			}

			c = alphabetIdx;
		}

	return s;
}

int main()
{
	solution("AB", 1);

	return 0;
}