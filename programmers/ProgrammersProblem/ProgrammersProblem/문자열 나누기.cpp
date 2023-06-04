#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int index = 0;
    int temp1 = 0, temp2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[index] == s[i]) {
            temp1++;
        }
        else {
            temp2++;
        }
        if (temp1 == temp2 && temp1 != 0) {
            answer++;
            index = i + 1;
            if (index >= s.size()) {
                break;
            }
            temp1 = 0;
            temp2 = 0;
        }
        else if (i == s.size() - 1) {
            answer++;
        }
    }

    return answer;
}