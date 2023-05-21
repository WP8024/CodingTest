#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> temp;
    for (auto item : score) {
        temp.push_back(item);
        sort(temp.begin(), temp.end());
        if (temp.size() <= k) {
            answer.push_back(temp.front());
        }
        else {
            answer.push_back(*(temp.end() - k));
        }
    }

    return answer;
}