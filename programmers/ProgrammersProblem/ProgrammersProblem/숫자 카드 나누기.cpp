#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int a = arrayA[0];
    int b = arrayB[0];
    for (int i = 1; i < arrayA.size(); i++) {
        a = gcd(a, arrayA[i]);
    }
    for (int i = 1; i < arrayB.size(); i++) {
        b = gcd(b, arrayB[i]);
    }

    if (a != 1) {
        for (auto i : arrayB) {
            if (i % a == 0) {
                a = 0;
                break;
            }
        }
    }
    if (b != 1) {
        for (auto i : arrayA) {
            if (i % b == 0) {
                b = 0;
                break;
            }
        }
    }

    answer = max(a, b);
    if (answer == 1) answer = 0;
    return answer;
}