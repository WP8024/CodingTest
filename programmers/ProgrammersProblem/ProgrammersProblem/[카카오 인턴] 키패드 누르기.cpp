#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lcur = 3, rcur = 3;
    int temp = 0;
    for (auto i : numbers) {
        if (i == 1 || i == 4 || i == 7) {
            answer += "L";
            lcur = i / 3;
        }
        else if (i == 3 || i == 6 || i == 9) {
            answer += "R";
            rcur = (i/3)-1;
        }
        else {
            if (i == 0) {
                i = 10;
                temp = i / 3;
            }
            else {
                temp = i / 3;
            }

            if (abs(lcur - temp) == abs(rcur - temp)) {
                if (hand == "right") {
                    answer += "R";
                    rcur = i / 3;
                }
                else {
                    answer += "L";
                    lcur = i / 3;
                }
            }
            else if (abs(temp - lcur) < abs(temp - rcur)) {
                answer += "L";
                lcur = i / 3;
            }
            else {
                answer += "R";
                rcur = i / 3;
            }
        }
    }

    return answer;
}
