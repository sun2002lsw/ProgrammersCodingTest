#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	vector<int> cloth(n, 1);

	for (const int studentID : lost)
		cloth[studentID - 1]--;

	for (const int studentID : reserve)
		cloth[studentID - 1]++;

	for (size_t i = 0; i < cloth.size(); i++)
		if (cloth[i] == 0)
			if (i > 0 && cloth[i - 1] > 1)
			{
				cloth[i - 1]--;
				cloth[i]++;
			}
			else if (i < cloth.size() - 1 && cloth[i + 1] > 1)
			{
				cloth[i + 1]--;
				cloth[i]++;
			}

	int answer = 0;
	for (const int cnt : cloth)
		if (cnt > 0)
			answer++;

	return answer;
}
