#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    int count = 0;
    int sum = 0;
    int temp = 0;
    bool nonumber = false;
    vector<int> answer;

    int maxsize = 0;
    for (int i = 0; i < keymap.size(); i++) {
        if (maxsize <= keymap[i].size()) {
            maxsize = keymap[i].size();
        }
    }

    for (int i = 0; i < targets.size(); i++) {
        sum = 0;
        nonumber = false;
        for (int j = 0; j < targets[i].size(); j++) {
            count = 0;
            temp = 0;

            while (1) {
                if (count < maxsize) {
                    for (int l = 0; l < keymap.size(); l++) {
                        if (count >= keymap[l].size()) {}
                        else if (targets[i][j] == keymap[l][count]) {
                            temp += count + 1;
                            break;
                        }
                    }
                }
                else {
                    nonumber = true;
                    break;
                }
                if (temp != 0) {
                    sum += temp;
                    break;
                }
                count++;
            }

            if (nonumber) {
                sum = -1;
                break;
            }
        }
        if (sum != 0) {
            answer.push_back(sum);
        }
    }



    return answer;
}


int main() {

    vector<string> keymap,targets;
    string temp;

    cout << "키맵 입력 0 입력시 종료" << "\n";

    while (1) {
        cin >> temp;

        if (temp == "0") {
            break;
        }

        keymap.push_back(temp);
    }

    cout << "타겟 입력 0 입력시 종료" << "\n";

    while (1) {
        cin >> temp;

        if (temp == "0") {
            break;
        }
        targets.push_back(temp);

    }
    
    cout << "솔루션함수 시작" << "\n";
    solution(keymap, targets);

    return 0;
}