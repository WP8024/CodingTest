#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int temp = 0;
    int unknown = 0;

    for (auto& index : lottos) {
        if (index == 0) {
            unknown++;
        }
        if (find(win_nums.begin(), win_nums.end(), index) != win_nums.end()) {
            temp++;
        }
    }
    if (temp + unknown <= 1) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - (temp + unknown));
    }

    if (temp <= 1) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - temp);
    }
    return answer;
}