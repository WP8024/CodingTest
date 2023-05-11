#include <string>
#include <vector>

using namespace std;
int divisor(int n) {
    int num = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            num++;
            if (i * i < n) {
                num++;
            }
        }
    }
    return num;
}

int solution(int left, int right) {
    int answer = 0;
    int temp = 0;
    for (int i = left; i <= right; i++) {
        temp = divisor(i);
        if (temp % 2 == 1) {
            answer -= i;
        }
        else {
            answer += i;
        }
    }
    return answer;
}