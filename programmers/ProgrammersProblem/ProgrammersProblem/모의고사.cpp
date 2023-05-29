#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[6] = { 1,2,3,4,5 };
    int b[9] = { 2,1,2,3,2,4,2,5 };
    int c[11] = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int> count(3, 0);
    int max = 0;
    for (int i = 0; i < answers.size(); i++) {
        int t1 = i % 5, t2 = i % 8, t3 = i % 10;
        if (answers[i] == a[t1]) {
            count[0]++;
        }
        if (answers[i] == b[t2]) {
            count[1]++;
        }
        if (answers[i] == c[t3]) {
            count[2]++;
        }
    }

    for (auto i : count) {
        if (i > max) {
            max = i;
        }
    }

    for (int i = 0; i < count.size(); i++) {
        if (max == count[i]) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}