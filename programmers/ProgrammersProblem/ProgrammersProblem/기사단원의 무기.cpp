#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> temp;
    int divisor = 0;


    for (int i = 1; i <= number; i++) {
        divisor = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                divisor++;
                if (j * j < i) {
                    divisor++;
                }
            }
        }
        if (divisor > limit) {
            answer += power;
        }
        else {
            answer += divisor;
        }
    }

    return answer;
}