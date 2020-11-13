#include <queue>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class DualPriorityQueue
{
public:
	void Insert(int n)
	{
		auto ptr = make_shared<int>(n);

		maxPQ.push(ptr);
		minPQ.push(ptr);
	}

	void DeleteMin()
	{
		if (minPQ.empty())
			return;

		minPQ.pop();
		GarbageCollection();
	}

	void DeleteMax()
	{
		if (maxPQ.empty())
			return;

		maxPQ.pop();
		GarbageCollection();
	}

	void GarbageCollection()
	{
		while (!minPQ.empty() && minPQ.top().use_count() == 1)
			minPQ.pop();
		while (!maxPQ.empty() && maxPQ.top().use_count() == 1)
			maxPQ.pop();
	}

	int GetMin() { return minPQ.empty() ? 0 : *minPQ.top(); }
	int GetMax() { return maxPQ.empty() ? 0 : *maxPQ.top(); }

	struct MinPQ
	{
		bool operator()(const shared_ptr<int>& lhs, const shared_ptr<int>& rhs)
		{
			return *lhs > *rhs;
		}
	};

	struct MaxPQ
	{
		bool operator()(const shared_ptr<int>& lhs, const shared_ptr<int>& rhs)
		{
			return *lhs < *rhs;
		}
	};

private:
	priority_queue<shared_ptr<int>, vector<shared_ptr<int>>, MinPQ>	minPQ;
	priority_queue<shared_ptr<int>, vector<shared_ptr<int>>, MaxPQ> maxPQ;
};

vector<int> solution(vector<string> operations) {
	DualPriorityQueue dpq;

	for (const string& op : operations)
	{
		int number = atoi(op.substr(2).c_str());

		if (op[0] == 'I')
			dpq.Insert(number);
		else
			number < 0 ? dpq.DeleteMin() : dpq.DeleteMax();
	}
		
	vector<int> answer = { dpq.GetMax(), dpq.GetMin() };
	return answer;
}

int main()
{
	vector<string> operations = { "I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6" };
	solution(operations);

	return 0;
}