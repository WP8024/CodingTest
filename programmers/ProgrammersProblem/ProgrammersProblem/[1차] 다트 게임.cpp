#include <string>
#include <cmath>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    string str;
    int num = 0;
    for (auto text : dartResult) {
        if (isdigit(text)) {
            str += text;
        }
        else if (isalpha(text)) {
            num = stoi(str);
            str.clear();
            if (text == 'S') {
                score.push_back(pow(num, 1));
            }
            else if (text == 'D') {
                score.push_back(pow(num, 2));
            }
            else if (text == 'T')
                score.push_back(pow(num, 3));
        }
        else {
            if (text == '*') {
                if (score.size() > 1) {
                    score[score.size() - 2] *= 2;
                }
                score[score.size() - 1] *= 2;
            }
            else if (text == '#') {
                score[score.size() - 1] -= 2 * score[score.size() - 1];
            }
        }
    }
    for (auto i : score) {
        answer += i;
    }
    return answer;
}