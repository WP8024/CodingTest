#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pqA(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<int>>  pqB(B.begin(), B.end());

    while (!pqB.empty()) {
        if (pqA.top() < pqB.top()) {
            answer++;
            pqA.pop();
            pqB.pop();
        }
        else {
            pqB.pop();
        }
    }
    return answer;
}