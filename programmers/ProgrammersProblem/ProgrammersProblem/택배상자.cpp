#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st;
    queue<int> q;
    int temp = 1;
    for (auto i : order) {
        q.push(i);
    }

    while (!q.empty()) {
        if (q.front() >= temp) {
            st.push(temp);
            temp++;
        }
        else if (q.front() == st.top()) {
            q.pop();
            st.pop();
            answer++;
        }
        else {
            break;
        }
    }

    return answer;
}