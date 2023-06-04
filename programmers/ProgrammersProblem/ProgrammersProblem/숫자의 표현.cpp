#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int temp = 1;
    int start = 1, end = 1;

    while (end != n) {
        if (temp == n) {
            end++;
            temp += end;
            answer++;
        }
        else if (temp < n) {
            end++;
            temp += end;
        }
        else {
            temp -= start;
            start++;
        }
    }
    return answer;
}