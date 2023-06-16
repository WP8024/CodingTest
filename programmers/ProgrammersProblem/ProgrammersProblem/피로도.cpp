#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<vector<pair<int, int>>> fatiguelist;
    vector<pair<int, int>> fatigue;

    for (auto index : dungeons) {
        fatigue.push_back(make_pair(index[0], index[1]));
    }
    sort(fatigue.begin(), fatigue.end(), cmp);

    

    return answer;
}

int main() {

    solution(80, { {80, 20},{50, 40},{30, 10} });

    return 0;
}