#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int temp = 0;


    if (a < 0 && b>0) {
        temp = (b - a);
    }
    else if (a > 0 && b < 0) {
        temp = (a - b);
    }
    else {
        temp = (abs)(a - b);
    }

    double midle = (double)(a + b) / 2;
    answer = midle * (temp + 1);



    return answer;
}