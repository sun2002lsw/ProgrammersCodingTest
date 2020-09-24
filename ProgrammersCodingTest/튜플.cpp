#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

set<int> extractTupleSet(const string& s, size_t curIdx)
{
	set<int> tupleSet;

	for (; s[curIdx] != '}'; curIdx++)
		if (s[curIdx] == '{' || s[curIdx] == ',')
			tupleSet.insert(atoi(&s[curIdx + 1]));

	return tupleSet;
}

vector<int> solution(string s) {
	vector<set<int>> tupleSetVec;

	for (size_t idx = 1; idx < s.size(); idx++)
		if (s[idx] == '{')
			tupleSetVec.push_back(extractTupleSet(s, idx));
	sort(tupleSetVec.begin(), tupleSetVec.end(), [](set<int>& lhs, set<int>& rhs) { return lhs.size() < rhs.size(); });

	vector<int> answer;

	answer.push_back(*tupleSetVec[0].begin());
	for (size_t idx = 1; idx < tupleSetVec.size(); idx++)
		set_difference(tupleSetVec[idx].begin(), tupleSetVec[idx].end(), tupleSetVec[idx - 1].begin(), tupleSetVec[idx - 1].end(), back_inserter(answer));

	return answer;
}

int main()
{
	string s = "{{20,111},{111}}";
	solution(s);

	return 0;
}