#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int binarycount(int n) {
    string temp = "";
    while (n != 0) {
        temp += to_string(n % 2);
        n /= 2;
    }
    return count(temp.begin(), temp.end(), '1');
}

int solution(int n) {
    int answer = 0;
    int num = binarycount(n);
    answer = n + 1;
    while (num != binarycount(answer)) {
        answer++;
    }

    return answer;
}