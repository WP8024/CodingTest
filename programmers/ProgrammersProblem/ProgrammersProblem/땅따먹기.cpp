#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();
    int temp = 0, cur = 5, count = 0;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
            for (int l = 0; l < 4; l++) {
                if (j != l) {
                    temp = max(temp, land[i][l]);
                }
            }
            land[i - 1][j] += temp;
            temp = 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        answer = max(land[0][i], answer);
    }



    return answer;
}