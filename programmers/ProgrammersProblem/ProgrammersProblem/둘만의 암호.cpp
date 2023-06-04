#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<char> change;
    map<char, char> alphamap;
    int temp = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (skip.find(c) == string::npos) {
            change.push_back(c);
        }
    }
    for (int i = 0; i < change.size(); i++) {
        alphamap[change[i]] = change[(i + index) % change.size()];
    }
    for (auto i : s) {
        answer += alphamap[i];
    }
    return answer;
}