#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> namescore;
    int temp = 0;

    for (int i = 0; i < name.size(); ++i) {
        namescore[name[i]] = yearning[i];
    }

    for (auto item : photo) {
        temp = 0;
        for (auto index : item) {
            temp += namescore[index];
        }
        answer.push_back(temp);
    }
    return answer;
}