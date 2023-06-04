#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> reportcount;

    for (auto index : id_list) {
        reportcount[index] = 0;
    }
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    string temp = "";

    for (auto index : report) {
        for (int i = 0; i < index.size(); i++) {
            if (index[i] == ' ') {
                temp = index.substr(i + 1);
                reportcount[temp]++;
                break;
            }
        }
    }

    for (auto index : id_list) {
        answer.push_back(reportcount[index]);
    }
    return answer;
}
