#include <iostream>
#include <string>
using namespace std;

int func(string& s, int i) {
    int count = 0;
    int count2 = 0;
    int end = s.size() - 1 - i;

    for (count = 0; i + count < s.size() && i - count >= 0; count++) {
        if (s[i + count] != s[i - count]) {
            break;
        }
    }
    for (count2 = 0; i + 1 + count2 < s.size() && i - count2 >= 0; count2++) {
        if (s[i + 1 + count2] != s[i - count2]) {
            break;
        }
    }
    count = count * 2 - 1;
    count2 = count2 * 2;
    count = max(count, count2);
    return count;
}

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        answer = max(answer, func(s, i));
    }

    return answer;
}