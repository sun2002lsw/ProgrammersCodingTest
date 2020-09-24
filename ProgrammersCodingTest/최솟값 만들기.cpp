#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), less<int>());

	int answer = 0;
	for (size_t i = 0; i < A.size(); i++)
		answer += A[i] * B[i];

	return answer;
}
