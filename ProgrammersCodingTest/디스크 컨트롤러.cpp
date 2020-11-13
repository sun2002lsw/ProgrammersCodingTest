#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
	Job(int s, int p) : startTime(s), processTime(p) {}

	int startTime;
	int processTime;
	int completeTime;
};

struct SJF // Shortest job first
{
	bool operator()(const Job& lhs, const Job& rhs)
	{
		return lhs.processTime > rhs.processTime;
	}
};

struct FIFO // fist in first out
{
	bool operator()(const Job& lhs, const Job& rhs)
	{
		return lhs.startTime < rhs.startTime;
	}
};

vector<Job> jobVec;
queue<Job> jobQueue;
priority_queue<Job, vector<Job>, SJF> jobPQ;
vector<Job> completeJobs;

void CreateJobQueue(const vector<vector<int>>& jobs)
{
	for (size_t i = 0; i < jobs.size(); i++)
		jobVec.emplace_back(jobs[i][0], jobs[i][1]);

	FIFO fifo;
	sort(jobVec.begin(), jobVec.end(), fifo);

	for (const Job& job : jobVec)
		jobQueue.push(job);
}

void GetJobsFromJobQueue(int curTime)
{
	while (!jobQueue.empty() && jobQueue.front().startTime <= curTime)
	{
		jobPQ.push(jobQueue.front());
		jobQueue.pop();
	}
}

int GetAvgElapsedTime()
{
	int totalElapsedTime = 0;
	for (const Job& job : completeJobs)
		totalElapsedTime += job.completeTime - job.startTime;

	return totalElapsedTime / (int)completeJobs.size();
}

int solution(vector<vector<int>> jobs) {
	CreateJobQueue(jobs);

	for (int curTime = 0; !jobQueue.empty() || !jobPQ.empty();)
	{
		if (jobPQ.empty() && curTime < jobQueue.front().startTime)
			curTime = max(curTime, jobQueue.front().startTime);

		GetJobsFromJobQueue(curTime);

		if (!jobPQ.empty())
		{
			Job job = jobPQ.top();
			jobPQ.pop();

			curTime += job.processTime;
			job.completeTime = curTime;

			completeJobs.push_back(job);
		}
	}

	return GetAvgElapsedTime();
}

int main()
{
	vector<vector<int>> jobs = {{0, 10}, {4, 10}, {5, 11}, {15, 2}};
	int ans = solution(jobs);

	return 0;
}
