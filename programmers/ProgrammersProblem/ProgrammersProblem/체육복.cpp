#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    int max = reserve.size();
    int min = lost.size();
    int cur = 0;
    for (int i = 0; i < lost.size();) {
        if (abs(lost[i] - reserve[cur]) == 1) {
            answer++;
            cur++;
            i++;
        }
        else {
            if (lost[i] > reserve[cur]) {
                cur++;
            }
            else {
                i++;
            }
        }
    }
    return answer;
}

