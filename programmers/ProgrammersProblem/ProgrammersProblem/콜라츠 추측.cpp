#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = -1;
    int count = 1;
    long temp = num;

    while (count != 500) {
        count++;
        if (temp == 1) {
            answer++;
            return answer;
        }
        else if (temp % 2 != 0) {
            temp = temp * 3 + 1;
            answer++;
        }
        else {
            temp = temp / 2;
            answer++;
        }
    }

    return -1;
}