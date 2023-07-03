#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1, q2;
    long long temp1 = 0, temp2 = 0, target = 0;
    int maxsize = (queue1.size() + queue2.size()) * 2;
    bool check = true;
    for (auto i : queue1) {
        q1.push(i);
        temp1 += i;
    }
    for (auto i : queue2) {
        q2.push(i);
        temp2 += i;
    }

    target = temp1 + temp2;
    if (target % 2 == 1) {
        return -1;
    }
    else {
        target /= 2;
    }
    int t = 0;
    for (int i = 0; i < maxsize; i++) {
        if (temp1 < temp2) {
            t = q2.front();
            q1.push(t);
            q2.pop();
            answer++;
            temp2 -= t;
            temp1 += t;
        }
        else if (temp1 > temp2) {
            t = q1.front();
            q2.push(t);
            q1.pop();
            answer++;
            temp1 -= t;
            temp2 += t;
        }
        else {
            check = false;
            break;
        }
    }
    if (check) return -1;
    return answer;
}