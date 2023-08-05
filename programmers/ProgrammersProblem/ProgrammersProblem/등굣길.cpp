#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int>> vec(n + 1, vector<int>(m + 1, 1));

    for (auto i : puddles) {
        vec[i[1]][i[0]] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vec[i][j] == 0) {
                vec[i][j] = 0;
            }
            else if (i == 1) {
                vec[i][j] = vec[i][j - 1];
            }
            else if (j == 1) {
                vec[i][j] = vec[i - 1][j];
            }
            else {
                vec[i][j] = (vec[i - 1][j] + vec[i][j - 1]) % 1000000007;
            }
        }
    }
    answer = vec[n][m];
    return answer;
}