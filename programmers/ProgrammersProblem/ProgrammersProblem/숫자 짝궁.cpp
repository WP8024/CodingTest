#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(char x, char y) {
    return x > y;
}
string solution(string X, string Y) {
    string answer = "";
    map<int, int> A, B;
    for (auto i : X) {
        A[i - '0']++;
    }
    for (auto i : Y) {
        B[i - '0']++;
    }
    for (int i = 0; i <= 9; i++) {
        int temp = min(A[i], B[i]);
        if (temp != 0) {
            answer.append(temp, i + '0');
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    if (answer.front() == '0') {
        answer = "0";
    }
    if (answer.empty()) {
        answer += "-1";
    }
    return answer;
}