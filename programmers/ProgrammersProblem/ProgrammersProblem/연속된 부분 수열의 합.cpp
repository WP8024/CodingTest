#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int target = sequence[0];
    int start = 0, end = 0;
    vector<pair<int, int>> temp;
    for (; start < sequence.size();) {
        if (target < k && end < sequence.size()) {
            end++;
            target += sequence[end];
        }
        else if (target == k) {
            temp.push_back(make_pair(start, end));
            target -= sequence[start];
            start++;
        }
        else {
            target -= sequence[start];
            start++;
        }
    }

    sort(temp.begin(), temp.end(), [](pair<int, int> a, pair<int, int> b)->bool {
        if (a.second - a.first == b.second - b.first) {
            return a.first < b.first;
        }
        return a.second - a.first < b.second - b.first;
    });
    answer.push_back(temp[0].first);
    answer.push_back(temp[0].second);
    return answer;
}