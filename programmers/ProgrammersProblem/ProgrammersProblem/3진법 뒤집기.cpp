#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    string temp;
    while (n != 0) {
        temp += to_string(n % 3);
        n /= 3;
    }
    reverse(temp.begin(), temp.end());
    string str;
    for (int i = 0; i < temp.size(); i++) {
        str = "";
        str += temp[i];
        answer += stoi(str) * pow(3, i);
    }
    return answer;
}