#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if (s.size() == 4 || s.size() == 6) {

    }
    else {
        return false;
    }

    for (const auto& ch : s) {
        if (ch >= '0' && ch <= '9') {

        }
        else {
            return false;
        }
    }

    return answer;
}