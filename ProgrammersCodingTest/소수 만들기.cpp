#include <vector>

using namespace std;

int solution(vector<int> nums) {
	vector<bool> isPrime(3000 + 1, true);
	int answer = 0;

	// eratosthenes
	isPrime[0] = isPrime[1] = false;
	for (int p = 2; p * p <= 3000; p++)
		if (isPrime[p])
			for (int i = p * p; i <= 3000; i += p)
				isPrime[i] = false;

	// three number sum
	for (size_t i = 0; i < nums.size(); i++)
		for (size_t j = i + 1; j < nums.size(); j++)
			for (size_t k = j + 1; k < nums.size(); k++)
				if (isPrime[nums[i] + nums[j] + nums[k]])
					answer++;

	return answer;
}
