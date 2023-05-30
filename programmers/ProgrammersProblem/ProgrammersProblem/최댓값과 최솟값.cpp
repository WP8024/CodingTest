#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string str;
    vector<int> temp;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]) || s[i] == '-') {
            str += s[i];
        }
        else {
            temp.push_back(stoi(str));
            str.clear();
        }
        if (i == s.size() - 1) {
            temp.push_back(stoi(str));
            str.clear();
        }
    }

    sort(temp.begin(), temp.end());
    answer = to_string(temp.front()) + " " + to_string(temp.back());
    return answer;
}