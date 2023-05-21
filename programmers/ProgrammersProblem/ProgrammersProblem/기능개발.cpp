#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> complete;
    int temp = 0;
    for (int i = 0; i < progresses.size(); i++) {
        temp = 100 - progresses[i];
        if (temp % speeds[i] != 0) {
            temp = temp / speeds[i] + 1;
            complete.push_back(temp);
        }
        else {
            temp = temp / speeds[i];
            complete.push_back(temp);
        }
    }
    int count = 0;
    temp = 0;
    for (int i = 0; i < complete.size(); i++) {
        if (temp >= complete[i]) {
            count++;
        }
        if (temp < complete[i]) {
            if (temp != 0) {
                answer.push_back(count);
            }
            temp = complete[i];
            count = 1;
        }
        if (i == complete.size() - 1) {
            answer.push_back(count);
        }
    }

    return answer;
}