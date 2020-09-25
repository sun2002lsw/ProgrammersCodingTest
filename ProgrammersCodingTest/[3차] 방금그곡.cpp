#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void ConvertSharpToLowercase(string& str)
{
    for (string::size_type pos = str.find('#'); pos != string::npos; pos = str.find('#', pos + 1))
        str[pos - 1] = tolower(str[pos - 1]);

    for (auto iter = find(str.begin(), str.end(), '#'); iter != str.end(); iter = find(str.begin(), str.end(), '#'))
        str.erase(iter);
}

struct MusicInfo
{
    MusicInfo(const string& startTime, const string& endTime, const string& title, const string& music);

    string title_;
    string music_;
    int musicLen_;
    int startTime_;
};

MusicInfo::MusicInfo(const string& startTime, const string& endTime, const string& title, const string& music)
{
    title_ = title;

    int startHour = atoi(startTime.substr(0, 2).c_str());
    int startMin = atoi(startTime.substr(3, 2).c_str());
    int endHour = atoi(endTime.substr(0, 2).c_str());
    int endMin = atoi(endTime.substr(3, 2).c_str());

    startTime_ = startHour * 60 + startMin;
    musicLen_ = endHour * 60 + endMin - startTime_;

    int loopCnt = musicLen_ / music.size();
    for (int loop = 0; loop < loopCnt; loop++)
        music_ += music;

    int remainLen = musicLen_ - loopCnt * music.size();
    music_ += music.substr(0, remainLen);
}

MusicInfo StringToMusicInfo(const string& mInfo)
{
    string startTime, endTime, title, music;

    startTime = mInfo.substr(0, 5);
    endTime = mInfo.substr(6, 5);

    string::size_type pos = mInfo.find(',', 12);
    title = mInfo.substr(12, pos - 12);
    music = mInfo.substr(pos + 1);

    ConvertSharpToLowercase(music);

    return MusicInfo(startTime, endTime, title, music);
}

string solution(string m, vector<string> musicinfos) {
    ConvertSharpToLowercase(m);

    vector<MusicInfo> mInfos;
    for (const string& musicInfoStr : musicinfos)
        mInfos.push_back(StringToMusicInfo(musicInfoStr));

    sort(mInfos.begin(), mInfos.end(), [](const MusicInfo& lhs, const MusicInfo& rhs) { return lhs.musicLen_ > rhs.musicLen_; });

    for (const auto& musicInfo : mInfos)
        if (musicInfo.music_.find(m) != string::npos)
            return musicInfo.title_;

    return "(None)";
}

int main()
{
    string m = "A#";
    vector<string> musicinfos = { "13:00,13:05,Lord of the Rings,A#"};

    solution(m, musicinfos);

    return 0;
}
