#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
	set<int> sumSet;
	for (size_t i = 0; i < numbers.size() - 1; i++)
		for (size_t j = 1; j < numbers.size(); j++)
			if (i != j)
				sumSet.insert(numbers[i] + numbers[j]);

	vector<int> answer;
	for (int number : sumSet)
		answer.push_back(number);

	return answer;
}
