#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> participantSet;

    for (const string& p : participant)
        participantSet.insert(p);

    for (const string& c : completion)
        participantSet.erase(participantSet.find(c));
   
    return *participantSet.begin();
}

int main()
{
    vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string> completion = { "stanko", "ana", "mislav" };

   solution(participant, completion);

    return 0;
}
