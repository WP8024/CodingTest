#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    int i = 0;
    for (auto index : priorities) {
        q.push(make_pair(i, index));
        i++;
    }
    vector<int> temp(priorities);
    sort(temp.begin(), temp.end(), [](int a, int b)->bool {
        return a > b;
    });

    i = 0;
    while (!q.empty()) {
        if (temp[i] == q.front().second) {
            if (location == q.front().first) {
                answer++; break;
            }
            q.pop();
            answer++;
            i++;
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}