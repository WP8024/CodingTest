#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for (auto i : numbers) {
        str.push_back(to_string(i));
    }
    sort(str.begin(), str.end(), cmp);
    for (auto s : str) {
        answer += s;
    }
    //tc11번 
    //ex) [0,0,0,0] result 0이 되는 경우
    if (answer.front() == '0') {
        answer = "0";
    }
    return answer;
}