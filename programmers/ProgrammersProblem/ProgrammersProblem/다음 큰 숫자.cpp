#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
string binary(int n) {
    string temp;
    while (n != 0) {
        temp += to_string(n % 2);
        n /= 2;
    }
    return temp;
}

int solution(int n) {
    int answer = 0;

    string temp = binary(n);

    for (int i = 0; i < temp.size(); i++) {
        if (i == 0) {
            temp[i] += '1';
        }
        if (temp[i] == '2') {
            temp[i] = '0';
            if (temp.size() == i + 1) {
                temp += "1";
            }
            else {
                temp[i + 1] += '1';
            }
        }
        else break;
    }

    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == '1') {
            answer += pow(2, i);
        }
    }

    return answer;
}


int main() {
    solution(15);

    return 0;
}