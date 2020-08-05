#include <queue>
#include <vector>

using namespace std;
using TimeSec = int;

TimeSec solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<pair<int, TimeSec>> truckQueue;
	TimeSec curTime = 0;
	int curWeight = 0;

	for (const int truck_weight : truck_weights)
	{
		bool truckWait = false;

		while (weight < curWeight + truck_weight)
		{
			const auto frontTruck = truckQueue.front();
			const int truckWeight = frontTruck.first;
			const TimeSec truckEnterTime = frontTruck.second;

			TimeSec waitSec = bridge_length - (curTime - truckEnterTime);
			if (waitSec > 0)
			{
				truckWait = true;
				curTime += waitSec;
			}

			curWeight -= truckWeight;
			truckQueue.pop();
		}

		if (truckWait == false)
			curTime++;

		curWeight += truck_weight;
		truckQueue.push(make_pair(truck_weight, curTime));
	}

	return curTime + bridge_length;
}
