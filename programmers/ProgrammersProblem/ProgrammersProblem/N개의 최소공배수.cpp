#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//유클리드 호제법응용시 간단
long long gcd(long long a, long long b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}


int solution(vector<int> arr) {
    long long answer = 1;
    sort(arr.begin(), arr.end());
    for (auto i : arr) {
        answer = lcm(answer, i);
    }
    return answer;
}