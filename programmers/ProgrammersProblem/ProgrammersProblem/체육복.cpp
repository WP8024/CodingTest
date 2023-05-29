#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int student[31] = { 1, };

    for (const auto& i : lost) {
        student[i] = 0;
    }
    for (const auto& i : reserve) {
        student[i] += 1;
    }
    for (int i = 1; i < n + 1; i++) {
        if (student[i] == 0) {
            if (i - 1 > 0 && student[i - 1] == 2) {
                student[i] += 1;
                student[i - 1] -= 1;
            }
            else if (i + 1 <= n && student[i + 1] == 2) {
                student[i] += 1;
                student[i + 1] -= 1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        if (student[i] == 0) {
            n--;
        }
    }
    answer = n + 1;
    return answer;
}

int main() {
    vector<int> lost = { 2,4 };
    vector<int> reserve = { 1,3,5 };

    solution(5, lost, reserve);
}