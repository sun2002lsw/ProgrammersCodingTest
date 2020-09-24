#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> NumToVec(int n)
{
	vector<int> v;
	for (; n > 0; n = (n - n % 2) / 2)
		v.push_back(n % 2);

	return v;
}

int VecToNum(const vector<int>& v)
{
	int n = 0;
	for (size_t i = 0; i < v.size(); i++)
		if (v[i])
			n += (int)pow(2, i);

	return n;
}

void FindOneAndZero(vector<int>& v, vector<int>::iterator& one, vector<int>::iterator& zero)
{
	one = find(v.begin(), v.end(), 1);
	zero = find(one, v.end(), 0);

	if (zero == v.end())
	{
		v.push_back(0);
		one = v.end() - 2;
		zero = v.end() - 1;
	}
}

void AlignToLeft(vector<int>& v, const vector<int>::iterator end)
{
	size_t oneCnt = count(v.begin(), end, 1);
	size_t endIdx = end - v.begin();

	for (size_t idx = 0; idx < oneCnt; idx++)
		v[idx] = 1;
	for (size_t idx = oneCnt; idx < endIdx; idx++)
		v[idx] = 0;
}

int solution(int n) {
	vector<int> v = NumToVec(n);

	vector<int>::iterator one, zero;
	FindOneAndZero(v, one, zero);

	swap(*one, *zero);

	AlignToLeft(v, zero);

	return VecToNum(v);
}

int main()
{
	int answer = solution(15);
	return 0;
}
