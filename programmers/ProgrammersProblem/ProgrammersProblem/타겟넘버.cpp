#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
static int answer = 0;

void BFS(vector<int> num, int tgt) {
    queue<pair<int, int>> q1;
    q1.push(make_pair(0, num[0]));
    q1.push(make_pair(0, -num[0]));
    int cnt = 100;
    while (!q1.empty()) {

        int idx = q1.front().first;
        int res = q1.front().second;
        q1.pop();

        if (idx == num.size() - 1 && res == tgt) {
            answer += 1;
        }
        if (idx + 1 < num.size()) {
            q1.push(make_pair(idx + 1, res + num[idx + 1]));
            q1.push(make_pair(idx + 1, res - num[idx + 1]));
        }


    }


}

int solution(vector<int> numbers, int target) {
    int res = 0;
    int cnt = 0;
    //DFS(numbers, target, cnt, res);
    BFS(numbers, target);
    return answer;
}