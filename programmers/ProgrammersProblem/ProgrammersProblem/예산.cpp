#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    int temp = 0;
    for (const auto& cost : d) {
        temp += cost;
        if (temp <= budget) {
            answer++;
        }
    }
    return answer;
}