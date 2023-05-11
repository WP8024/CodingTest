#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pcount = 0, ycount = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'y' || s[i] == 'Y') {
            ycount++;
        }
        else if (s[i] == 'p' || s[i] == 'P') {
            pcount++;
        }
    }

    if (ycount == pcount) {
        answer = true;
    }
    else {
        answer = false;
    }
    return answer;
}