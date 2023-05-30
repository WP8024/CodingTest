#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mapset;
    for (auto i : participant) {
        mapset[i]++;
    }
    for (auto i : completion) {
        mapset[i]--;
    }

    for (auto iter = mapset.begin(); iter != mapset.end(); iter++) {
        if (iter->second == 1) {
            answer = iter->first;
        }
    }

    return answer;
}