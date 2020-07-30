#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	sort(stages.begin(), stages.end());

	queue<int> stagesQueue;
	for (const int stage : stages)
		stagesQueue.push(stage);

	vector<double> failRate(N + 1);
	for (int stage = 1; stage <= N; stage++)
	{
		int stuckUserCnt = 0, totalUserCnt = stagesQueue.size();
		for (; stagesQueue.front() == stage; stuckUserCnt++)
			stagesQueue.pop();

		failRate[stage] = (double)stuckUserCnt / (double)totalUserCnt;
	}

	vector<pair<double, int>> failRateWithStage;
	for (int stage = 1; stage <= N; stage++)
		failRateWithStage.emplace_back(-failRate[stage], stage);
	sort(failRateWithStage.begin(), failRateWithStage.end());
		
	vector<int> answer;
	for (const auto& f : failRateWithStage)
		answer.push_back(f.second);

	return answer;
}

int main()
{
	int N = 5;
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

	solution(N, stages);

	return 0;
}
