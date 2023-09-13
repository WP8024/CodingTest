#include <string>
#include <vector>
using namespace std;

string func(string s) {
    string u = "", v = "";
    int count = 0;

    if (s.empty()) {
        return s;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') count++;
        else count--;

        if (count == 0) {
            u = s.substr(0, i + 1);
            v = s.substr(i + 1);
            break;
        }
    }

    count = 0;
    for (int i = 0; i < u.size(); i++) {
        if (u[i] == '(') count++;
        else count--;
        if (count < 0) {
            string temp = "(";
            temp += func(v);
            temp += ")";
            for (int i = 1; i < u.size() - 1; i++) {
                if (u[i] == '(') {
                    temp += ")";
                }
                else {
                    temp += "(";
                }
            }
            u = temp;
            return u;
        }
    }

    return u + func(v);
}

string solution(string p) {
    string answer = "";
    answer = func(p);

    return answer;
}