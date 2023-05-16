#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for (const auto& list : commands) {
        temp.clear();
        int i = list[0] - 1;
        int j = list[1] - 1;
        int k = list[2] - 1;
        for (i; i <= j; i++) {
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
    }

    return answer;
}