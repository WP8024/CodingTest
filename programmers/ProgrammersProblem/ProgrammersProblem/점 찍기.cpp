#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long distance = pow(d, 2);
    long long temp1 = 0, temp2 = 0;
    int num;

    for (int i = 0; i * k <= d; i++) {
        temp1 = pow(i * k, 2);
        temp2 = distance - temp1;
        num = sqrt(temp2);
        answer += num / k + 1;
    }

    return answer;
}