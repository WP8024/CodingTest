#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> mapset;
    for (int i = 0; i < s.size(); ++i) {
        if (mapset[s[i]] == 0) {
            answer.push_back(-1);
            mapset[s[i]] = i + 1;
        }
        else {
            answer.push_back(i + 1 - mapset[s[i]]);
            mapset[s[i]] = i + 1;
        }
    }
    return answer;
}