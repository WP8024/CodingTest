#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string str;
    str = to_string(x);
    int temp = 0;
    for (int i = 0; i < str.size(); i++) {
        temp += str[i] - '0';
    }
    if (x % temp == 0) {
        answer = true;
    }
    else {
        answer = false;
    }
    return answer;
}