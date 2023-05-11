#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (auto ch : s) {
        if (ch >= 'a' && ch <= 'z' && ch + n > 'z') {
            ch += n - 'z' + 'a' - 1;
        }
        else if (ch >= 'A' && ch <= 'Z' && ch + n > 'Z') {
            ch += n - 'Z' + 'A' - 1;
        }

        else {
            if (ch != ' ') {
                ch += n;
            }
        }
        answer += ch;
    }

    return answer;
}