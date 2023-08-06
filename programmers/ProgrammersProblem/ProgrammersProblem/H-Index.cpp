#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    stack<int> st;
    sort(citations.begin(), citations.end(), [](int a, int b)->bool {
        return a > b;
    });
    int h = 0;
    for (auto i : citations) {
        st.push(i);
        h = st.size();
        if (st.top() < h) {
            st.pop();
            h = st.size();
            break;
        }
    }
    answer = h;

    return answer;
}