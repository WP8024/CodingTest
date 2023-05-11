#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double temp;
    temp = sqrt(n);
    if ((int)(temp + 1) - temp != 1) {
        return -1;
    }
    else {
        return pow(temp + 1, 2);
    }

    return answer;
}