#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPromising(const vector<char>& candidate, const char f1, const char f2, const char op, const int dis)
{
	auto f1_idx = find(candidate.begin(), candidate.end(), f1);
	auto f2_idx = find(candidate.begin(), candidate.end(), f2);
	const int distance = abs(f1_idx - f2_idx) - 1;

	switch (op)
	{
	case '=':
		return distance == dis;
	case '<':
		return distance < dis;
	case '>':
		return distance > dis;
	}
}

bool IsPromising(const vector<char>& candidate, const vector<string>& data)
{
	for (const string& d : data)
	{
		const char f1 = d[0];
		const char f2 = d[2];
		const char op = d[3];
		const int dis = atoi(&d[4]);

		if (IsPromising(candidate, f1, f2, op, dis) == false)
			return false;
	}

	return true;
}

int solution(int n, vector<string> data) {
	vector<char> candidate = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
	sort(candidate.begin(), candidate.end());

	int answer = 0;
	do 
	{
		if (IsPromising(candidate, data))
			answer++;
	} 
	while (next_permutation(candidate.begin(), candidate.end()));

	return answer;
}

int main()
{
	int answer = solution(2, { "N~F=0", "R~T>2" });

	return 0;
}
