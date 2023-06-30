#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> st;

    for (int i = 0; i < numbers.size(); i++) {
        if (!st.empty() && numbers[st.top()] < numbers[i]) {
            while (!st.empty()) {
                if (numbers[st.top()] < numbers[i]) {
                    answer[st.top()] = numbers[i];
                    st.pop();
                }
                else {
                    break;
                }
            }
        }
        st.push(i);
    }

    return answer;
}