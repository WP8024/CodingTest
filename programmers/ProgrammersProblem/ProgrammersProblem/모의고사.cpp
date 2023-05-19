#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[6] = { 1,2,3,4,5 };
    int b[9] = { 2,1,2,3,2,4,2,5 };
    int c[11] = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int> count(3, 0);

    int max = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answer[i] == a[i % 5]) {
            count[0]++;
        }
        if (answer[i] == b[i % 8]) {
            count[1]++;
        }
        if (answer[i] == c[i % 10]) {
            count[2]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (count[i] > max) {
            max = count[i];
        }
    }
    for (int i = 0; i < 3; i++) {
        if (max == count[i]) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}

int main() {
    int a = -1;
    vector<int> temp;
    while (a != 0) {
        cin >> a;
        if (a == 0) {
            break;
        }
        temp.push_back(a);
    }
    solution(temp);
    return 0;
}