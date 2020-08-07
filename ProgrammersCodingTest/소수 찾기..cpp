#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>

#define MAX 10000000

using namespace std;

vector<bool> isPrime(MAX, true);
void Eratos()
{
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= sqrt(MAX); i++)
		if (isPrime[i])
			for (int mul = i * i; mul < MAX; mul += i)
				isPrime[mul] = false;
}

set<string> combination;
string number;
void GetCombin(const string& numbers, size_t count)
{
	if (count == 0)
	{
		combination.insert(number);
		return;
	}

	for (size_t i = 0; i <= numbers.size() - count; i++)
	{
		number.push_back(numbers[i]);
		GetCombin(numbers.substr(i + 1), count - 1);
		number.pop_back();
	}
}

set<string> permutation;
void GetPermu(string number)
{
	sort(number.begin(), number.end());

	do permutation.insert(number);
	while (next_permutation(number.begin(), number.end()));
}

set<int> numbers_;
int solution(string numbers) {
	Eratos();

	for (size_t count = 1; count <= numbers.size(); count++)
		GetCombin(numbers, count);
	for (const string& number : combination)
		GetPermu(number);
	for (const string& number : permutation)
		numbers_.insert(atoi(number.c_str()));

	int answer = 0;
	for (const int number : numbers_)
		if (isPrime[number])
			answer++;

	return answer;
}

int main()
{
	string numbers = "011";
	int answer = solution(numbers);

	return 0;
}