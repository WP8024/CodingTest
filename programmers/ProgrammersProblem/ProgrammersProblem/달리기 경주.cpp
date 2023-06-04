#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> nametorank;
    map<int, string> ranktoname;
    int index = 0;
    string temp;
    for (auto str : players) {
        index++;
        nametorank[str] = index;
        ranktoname[index] = str;
    }
    for (auto str : callings) {
        index = nametorank[str];
        nametorank[str]--;
        temp = ranktoname[index - 1];
        nametorank[temp]++;
        ranktoname[index - 1] = str;
        ranktoname[index] = temp;
    }
    for (int i = 1; i <= players.size(); i++) {
        answer.push_back(ranktoname[i]);
    }
    return answer;
}