#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> a, b;

    for (auto i : topping) {
        b[i]++;
    }
    for (auto i : topping) {
        a[i]++;
        b[i]--;
        if (b[i] <= 0) {
            b.erase(i);
        }

        if (a.size() == b.size()) {
            answer++;
        }
    }


    return answer;
}