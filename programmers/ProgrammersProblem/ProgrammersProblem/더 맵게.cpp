#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto i : scoville) {
        pq.push(i);
    }
    int t1, t2, t3;
    while (pq.top() < K) {
        if (pq.size() == 1) {
            return -1;
        }
        t1 = pq.top();
        pq.pop();
        t2 = pq.top();
        pq.pop();
        t3 = t1 + (t2 * 2);
        pq.push(t3);
        answer++;
    }

    return answer;
}