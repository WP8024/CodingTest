#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    deque<pair<int, int>> dq;
    int cur_weight = 0;
    int time = 0;
    for (auto i : truck_weights) {
        time++;
        if (cur_weight + i > weight) {
            while (cur_weight + i > weight) {
                time = dq.front().second + bridge_length;
                cur_weight -= dq.front().first;
                dq.pop_front();
            }
        }
        dq.push_back(make_pair(i, time));
        cur_weight += i;
    }

    if (!dq.empty()) {
        time = dq.back().second + bridge_length;
    }
    answer = time;

    return answer;
}

int main() {

    solution(2, 10, { 7, 4, 5, 6 });

    return 0;
}