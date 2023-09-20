#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<int> st;

    for (auto ch : number) {
        if (st.empty() || k == 0) {
            st.push(ch - '0');
        }
        else {
            while (!st.empty()) {
                if (st.top() < ch - '0' && k > 0) {
                    st.pop();
                    k--;
                }
                else {
                    break;
                }
            }
            st.push(ch - '0');
        }
    }
    while (k > 0) {
        st.pop();
        k--;
    }

    while (!st.empty()) {
        answer += st.top() + '0';
        st.pop();
    }
    reverse(answer.begin(), answer.end());


    return answer;
}