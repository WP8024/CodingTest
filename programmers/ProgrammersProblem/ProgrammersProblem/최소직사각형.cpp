#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0, h = 0;
    int min, max;
    for (const auto& item : sizes) {
        if (item[0] >= item[1]) {
            max = item[0];
            min = item[1];
        }
        else {
            max = item[1];
            min = item[0];
        }
        if (w < max) {
            w = max;
        }
        if (h < min) {
            h = min;
        }
    }
    answer = w * h;
    return answer;
}