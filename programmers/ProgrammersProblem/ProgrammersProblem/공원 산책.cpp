#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int h = park.size(), w = park[0].size();
    int xpos = 0, ypos = 0;
    int temp = 0;
    bool pass = true;

    for (int i = 0; i < h; i++) {
        if (park[ypos][xpos] == 'S') break;
        for (int j = 0; j < w; j++) {
            if (park[i][j] == 'S') {
                ypos = i;
                xpos = j;
                break;
            }
        }
    }


    for (auto index : routes) {
        temp = index.back() - '0';
        pass = true;
        if (index.front() == 'E' && xpos + temp < w) {
            for (int i = 1; i <= temp; i++) {
                if (park[ypos][xpos + i] == 'X') {
                    pass = false;
                    break;
                }
            }
            if (pass) {
                xpos += temp;
            }
        }
        else if (index.front() == 'W' && xpos - temp >= 0) {
            for (int i = 1; i <= temp; i++) {
                if (park[ypos][xpos - i] == 'X') {
                    pass = false;
                    break;
                }
            }
            if (pass) {
                xpos -= temp;
            }
        }
        else if (index.front() == 'S' && ypos + temp < h) {
            for (int i = 1; i <= temp; i++) {
                if (park[ypos + i][xpos] == 'X') {
                    pass = false;
                    break;
                }
            }
            if (pass) {
                ypos += temp;
            }
        }
        else if (index.front() == 'N' && ypos - temp >= 0) {
            for (int i = 1; i <= temp; i++) {
                if (park[ypos - i][xpos] == 'X') {
                    pass = false;
                    break;
                }
            }
            if (pass) {
                ypos -= temp;
            }
        }
    }
    answer.push_back(ypos);
    answer.push_back(xpos);
    return answer;
}