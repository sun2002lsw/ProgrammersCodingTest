#include <cstring>

int cache[60000 + 1];

int GetCnt(int n)
{
	if (n < 4)
		return n;

	int &ret = cache[n];
	if (ret != -1)
		return ret;

	ret = GetCnt(n - 1) + GetCnt(n - 2);

	return ret %= 1000000007;
}

int solution(int n) {
	memset(cache, -1, sizeof(cache));

	return GetCnt(n);
}
