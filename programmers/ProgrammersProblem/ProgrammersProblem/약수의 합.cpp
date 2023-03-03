#include <string>
#include <vector>
#include <iostream>

using namespace std;
//https://school.programmers.co.kr/learn/courses/30/lessons/12928

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            answer += i;
           
        }
        cout << n % i << ", ";
    }
    cout << "\n";
    cout << "answer :" << answer;
    return answer;
}

int main() {
    int num;
    cin >> num;

    solution(num);
    return 0;
}