#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first - a.second < b.first - b.second) {
            return true;
        }
        else if (a.first - a.second == b.first - b.second) {
            if (a.first < b.first) {
                return true;
            }
            else return false;
        }

        return false;

    }
};


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<pair<int, pair<int, int>>> vec;

    for (auto i : dungeons) {
        vec.push_back(make_pair(dungeons.size(), make_pair(i[0], i[1])));
    }



    for (auto i : dungeons) {
        pq.push(make_pair(i[0], i[1]));
    }
    auto t = pq;
    while (!t.empty()) {
        cout << "요구량:" << t.top().first << " 소모량:" << t.top().second << endl;
        t.pop();
    }

    while (!pq.empty()) {
        if (k >= pq.top().first) {
            cout << "현재 피로도:" << k << " 요구피로도:" << pq.top().first << " 소모피로도:" << pq.top().second;
            k -= pq.top().second;
            cout << " 남은 피로도:" << k << endl;
            answer++;
        }
        pq.pop();
    }

    return answer;
}