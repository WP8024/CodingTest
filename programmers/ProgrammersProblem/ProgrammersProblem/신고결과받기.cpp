#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    map<string, int> report_count;
    map<string, vector<string>> report_seat;
    map<string, int> answercount;

    vector<string> report_list;
    string str;


    for (const auto& id : id_list) {
        answercount[id] = 0;
        for (const auto& list : report) {
            stringstream split(list);
            while (getline(split, str, ' ')) {
                report_list.push_back(str);
            }
            sort(report_list.begin(), report_list.end());
            report_list.erase(unique(report_list.begin(), report_list.end()), report_list.end());
        }
        report_seat[id] = report_list;

        for (const auto& list : report_list) {
            report_count[list] += 1;
        }

        report_list.clear();
    }

    for (int i = 0; i < id_list.size(); i++) {
        for (int j = 0; j < report_seat.size(); j++) {
            report_seat[id_list[i]][j] == report_count[id_list[i]];
            if (report_count[id_list[i]] >= k) {

            }
        }
    }

    for (const auto& id : id_list) {
        for (const auto& seat : report_seat[id]) {
            if (report_count[seat] >= k) {
                answercount[id] += 1;
            }
        }
    }

    for (const auto& id : id_list) {
        answer.push_back(answercount[id]);
    }

  

    return answer;
}


int main() {
    cout << "id_list 입력 종료0 \n";
    vector<string> id_list, report;
    string str1, str2;
    while (str1 != "0") {
        cin >> str1;
        id_list.push_back(str1);
    }

    cout << " report 입력 종료0 \n";
    while (str2 != "0") {
        cin >> str2;
        report.push_back(str2);
    }
    cout << " k 입력 종료 0 \n";
    int k=-1;
    while (k != 0) {
        cin >> k;
    }

    solution(id_list, report, k);

    return 0;
}

