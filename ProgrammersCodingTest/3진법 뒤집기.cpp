#include <list>
#include <cmath>

using namespace std;

list<int> ToThreeBase(int n)
{
	list<int> threeBase;
	for (; n > 0; n /= 3)
		threeBase.push_front(n % 3);

	return threeBase;
}

int ToTenBase(const list<int>& threeBase)
{
	long long sum = 0, exp = 0;
	for (const long long number : threeBase)
		sum += number * pow(3, exp++);

	return sum;
}

int solution(int n) {
	return ToTenBase(ToThreeBase(n));
}

int main()
{
	return solution(45);
}
