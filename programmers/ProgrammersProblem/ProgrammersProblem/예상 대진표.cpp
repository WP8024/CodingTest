#include <iostream>
#include <cmath>
using namespace std;

int divide(int& n) {
    if (n % 2 == 0) {
        n /= 2;
    }
    else {
        n = (n + 1) / 2;
    }
    return n;
}
int solution(int n, int a, int b)
{
    int answer = 0;

    while (n != 0) {
        answer++;
        if (abs(a - b) <= 1 && max(a, b) % 2 == 0) {
            return answer;
        }
        else {
            n /= 2;
            divide(a);
            divide(b);
        }
    }


    return answer;
}