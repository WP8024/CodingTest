#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int> vec(n + 1, 0);

    for (auto i : lost) {
        vec[i]--;
    }
    for (auto i : reserve) {
        vec[i]++;
    }

    for (int i = 1; i < n + 1; i++) {
        if (vec[i] == -1) {
            if (vec[i - 1] == 1) {
                vec[i] = 0;
                vec[i - 1] = 0;
            }
            else if (vec[i + 1] == 1 && i + 1 < n + 1) {
                vec[i] = 0;
                vec[i + 1] = 0;
            }

        }
    }
    answer = n - count(vec.begin() + 1, vec.end(), -1);
    return answer;
}