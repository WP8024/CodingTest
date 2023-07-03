#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;

    for (auto i : enemy) {
        pq.push(i);
        n -= i;
        if (n >= 0) {
            answer++;
        }
        else if (k > 0) {
            n += pq.top();
            pq.pop();
            k--;
            answer++;
        }
        else {
            break;
        }
    }
    return answer;
}