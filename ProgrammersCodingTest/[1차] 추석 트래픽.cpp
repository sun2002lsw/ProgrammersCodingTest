#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using millisec = time_t;
using logStartFinish = pair<millisec, millisec>;
using millisecPQ = priority_queue<millisec, vector<millisec>, greater<millisec>>;

vector<logStartFinish> logTimeVec;
millisecPQ finishTimeQueue;

millisec ConvertTimeToMilliSec(const string& timeStr)
{
	millisec hour = atoi(timeStr.substr(0, 2).c_str()) * 1000 * 3600;
	millisec min = atoi(timeStr.substr(3, 2).c_str()) * 1000 * 60;
	millisec sec = atoi(timeStr.substr(6, 2).c_str()) * 1000;
	millisec milli = atoi(timeStr.substr(9, 3).c_str());

	return hour + min + sec + milli;
}

millisec ConvertSecToMilliSec(const string& secondStr)
{
	millisec sec, milli = 0;
	size_t dotIdx = secondStr.find('.');

	sec = atoi(secondStr.substr(0, dotIdx).c_str()) * 1000;
	if (dotIdx < secondStr.size())
		milli = atoi(secondStr.substr(dotIdx + 1).c_str());

	return sec + milli;
}

bool comp(const logStartFinish& lhs, const logStartFinish& rhs)
{
	return lhs.first != rhs.first ? lhs.first < rhs.first : lhs.second < rhs.second;
}

void GetLogTime(const vector<string>& lines)
{
	for (const string& line : lines)
	{
		millisec finishTime = ConvertTimeToMilliSec(line.substr(11, 12));
		millisec processTime = ConvertSecToMilliSec(line.substr(24));

		logTimeVec.emplace_back(finishTime - processTime + 1, finishTime);
	}

	sort(logTimeVec.begin(), logTimeVec.end(), comp);
}

int GetProcessCnt(const logStartFinish& logTime)
{
	millisec startTime = logTime.first;
	millisec finishtime = logTime.second;

	while (!finishTimeQueue.empty() && finishTimeQueue.top() <= startTime - 1000)
		finishTimeQueue.pop();

	finishTimeQueue.push(finishtime);

	return static_cast<int>(finishTimeQueue.size());
}

int solution(vector<string> lines) {
	GetLogTime(lines);

	int answer = 0;
	for (const auto& logTime : logTimeVec)
		answer = max(answer, GetProcessCnt(logTime));

	return answer;
}

int main()
{
	vector<string> lines = {
		"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"
	};

	solution(lines);

	return 0;
}
