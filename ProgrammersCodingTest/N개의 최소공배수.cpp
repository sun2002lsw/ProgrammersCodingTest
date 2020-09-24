#include <vector>
using namespace std;

int GCD(int a, int b) { return (b == 0) ? a : GCD(b, a % b); }
int LCM(int a, int b) {	return a * b / GCD(a, b); }

int solution(vector<int> arr) {
	int answer = arr[0];
	for (size_t i = 1; i < arr.size(); i++)
		answer = LCM(answer, arr[i]);

	return answer;
}
