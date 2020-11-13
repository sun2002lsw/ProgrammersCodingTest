#include <set>
#include <vector>
using namespace std;

set<size_t> remainBalloonSet;

int solution(vector<int> a) {
	for (int smallest = INT32_MAX, i = 0; i < a.size(); i++)
		if (smallest > a[i])
		{
			smallest = a[i];
			remainBalloonSet.insert(a[i]);
		}

	for (int smallest = INT32_MAX, i = a.size() - 1; i > 0; i--)
		if (smallest > a[i])
		{
			smallest = a[i];
			remainBalloonSet.insert(a[i]);
		}

	return (int)remainBalloonSet.size();
}
