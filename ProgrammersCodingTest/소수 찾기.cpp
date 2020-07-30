#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int n) {
	vector<bool> isPrime;
	isPrime.resize(n + 1, true);

	for (int i = 2; i <= sqrt(n); i++)
		if (isPrime[i])
			for (int mul = i * i; mul <= n; mul += i)
				isPrime[mul] = false;

	return count(isPrime.begin() + 2, isPrime.end(), true);
}

int main()
{
	int answer = solution(1000000);

	return 0;
}
