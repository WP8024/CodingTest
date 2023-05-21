#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b) {
    return a > b;
}
int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), comp);
    int min = 0, temp = 0;
    for (const auto& item : score) {
        if (temp == m - 1) {
            answer += item * m;
            temp = 0;
        }
        else {
            temp++;
        }
    }
    return answer;
}