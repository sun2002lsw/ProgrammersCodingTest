#include <cmath>
#include <algorithm>

using namespace std;

long long GCD(long long a, long long b)
{
	if (a == 0)
		return b;

	return GCD(b % a, a);
}

long long DamagedSquareCnt(double w, double h)
{
	double slope = h / w, leftY = 0, rightY, notUsed;
	long long counter = 0;

	for (double x = 0; x < w; leftY = rightY, x++)
	{
		rightY = slope * (x + 1);
		
		if (modf(leftY, &notUsed) == 0)
			counter += 1;
		else
			counter += (ceil(leftY) < rightY ? 2 : 1);
	}

	return counter;
}

long long solution(int w, int h) {
	if (w < h)
		swap(w, h);

	long long totalCnt = (long long)w * (long long)h;
	long long gcd = GCD(w, h);
	long long small_w = w / gcd;
	long long small_h = h / gcd;

	return totalCnt - (DamagedSquareCnt(small_w, small_h) * gcd);
}

int main()
{
	int w = 8, h = 12;

	long long answer = solution(w, h);

	return 0;
}
