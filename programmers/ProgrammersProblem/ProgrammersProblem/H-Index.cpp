#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h = 0;
    sort(citations.begin(), citations.end());
    int start = 0, end = citations.size() - 1;
    while (start != end) {

        if (citations.size() - end > h) {
            end--;
            h = citations[end];
        }
        else if (citations[start] < h) {
            start++;
        }
        if (citations.size() - end >= h && citations[start] <= h) {
            answer = h;
            return answer;
        }
    }

    return answer;
}

int solution1(vector<int> citations) {
    int answer = 0;
    stable_sort(citations.begin(), citations.end(), [](int a, int b)->bool {
        return a > b;
    });
    stack<int> st;
    int h = 0;
    int n = citations.size();
    for (auto index : citations) {
        if (st.empty()) {
            st.push(index);
            h = index;
        }
        else {
            if (st.size() < h) {
                st.push(index);
                h = index;
            }
        }
    }
    while (!st.empty()) {
        if (st.top() > h && st.size() > h) {
            h++;
        }
        else if (st.top() == h || st.size() == h) {
            st.pop();
        }
        else {
            answer = h;
            break;
        }
    }

    return answer;
}

int main() {
    solution1({ 3,0,6,1,5 });
    return 0;
}