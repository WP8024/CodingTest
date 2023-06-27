#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}


vector<int> solution(string s) {
    vector<int> answer;
    string str;
    vector<vector<int>> vec;
    vector<int> temp;
    set<int> se;

    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == ',' && str.size() > 0) {
            temp.push_back(stoi(str));
            str.clear();
        }
        else if (s[i] == '}') {
            if (str.size() > 0) {
                temp.push_back(stoi(str));
                str.clear();
            }
            vec.push_back(temp);
            temp.clear();
        }
        if (isdigit(s[i])) {
            str += s[i];
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    for (auto i : vec) {
        for (auto j : i) {
            if (se.find(j) == se.end()) {
                se.insert(j);
                answer.push_back(j);
            }
        }
    }
    return answer;
}