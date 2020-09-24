#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
	size_t chooseCnt = nums.size() / 2;

	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	return min(nums.size(), chooseCnt);
}
