#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    map<int, int> mapset;
    for (auto i : section) {
        if (mapset[i] == 0) {
            answer++;
            if (i + m - 1 > n) {
                for (int j = 0; j < m; j++) {
                    mapset[n - j]++;
                }
            }
            else {
                for (int j = 0; j < m; j++) {
                    mapset[i + j]++;
                }
            }
        }
    }

    return answer;
}