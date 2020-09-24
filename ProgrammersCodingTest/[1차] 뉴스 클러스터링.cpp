#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, size_t> wordCnt_str1, wordCnt_str2;

void ToUpper(string& str1, string& str2)
{
	for (char& c : str1)
		c = toupper(c);

	for (char& c : str2)
		c = toupper(c);
}

void MakeSet(const string& str1, const string& str2)
{
	for (size_t i = 0; i < str1.size() - 1; i++)
		if (isalpha(str1[i]) && isalpha(str1[i + 1]))
			++wordCnt_str1[str1.substr(i, 2)];

	for (size_t i = 0; i < str2.size() - 1; i++)
		if (isalpha(str2[i]) && isalpha(str2[i + 1]))
			++wordCnt_str2[str2.substr(i, 2)];
}

double GetJaccard()
{
	double unionCnt = 0, intersectionCnt = 0;

	for (const auto& word : wordCnt_str1)
	{
		const size_t cnt1 = word.second;
		size_t& cnt2 = wordCnt_str2[word.first];

		intersectionCnt += min(cnt1, cnt2);

		unionCnt += cnt1;
		if (cnt2 >= cnt1)
			cnt2 -= cnt1;
		else
			cnt2 = 0;
	}

	for (const auto& word : wordCnt_str2)
		unionCnt += word.second;

	return unionCnt == 0 ? 1 : intersectionCnt / unionCnt;
}

int solution(string str1, string str2) {
	ToUpper(str1, str2);
	MakeSet(str1, str2);
	return static_cast<int>(GetJaccard() * 65536);
}

int main()
{
	string str1 = "aa1+aa2", str2 = "AAAA12";
	solution(str1, str2);
	return 0;
}
