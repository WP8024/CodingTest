#include <string>
#include <vector>
#include <queue>
using namespace std;


void dequeue(queue<pair<int, int>>& q, int& w, int& t, int l) {
    w -= q.front().first;
    t = q.front().second + l;
    q.pop();
    return;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> q;
    int cur_w = 0;

    for (auto i : truck_weights) {
        answer++;
        if (q.size() == bridge_length || q.front().second + bridge_length == answer) {
            dequeue(q, cur_w, answer, bridge_length);
        }
        while (cur_w + i > weight) {
            dequeue(q, cur_w, answer, bridge_length);
        }
        q.push(make_pair(i, answer));
        cur_w += i;
    }

    answer = q.back().second + bridge_length;

    return answer;
}