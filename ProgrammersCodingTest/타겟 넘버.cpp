#include <vector>

using namespace std;

int GetCnt(const vector<int>& numbers, size_t idx, int target)
{
	if (numbers.size() == idx)
		return target == 0;

	return GetCnt(numbers, idx + 1, target + numbers[idx]) + GetCnt(numbers, idx + 1, target - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
	return GetCnt(numbers, 0, target);
}
