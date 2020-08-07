#include <queue>
#include <vector>

using namespace std;
using PQ = priority_queue<int, vector<int>, greater<int>>;

int solution(vector<int> scoville, int K) {
	PQ scovilleQueue(scoville.begin(), scoville.end());

	int answer = 0;
	for (; scovilleQueue.top() < K; answer++) {
		if (scovilleQueue.size() == 1)
			return -1;

		int smallest1 = scovilleQueue.top(); scovilleQueue.pop();
		int smallest2 = scovilleQueue.top(); scovilleQueue.pop();

		scovilleQueue.push(smallest1 + (smallest2 * 2));
	}

	return answer;
}
