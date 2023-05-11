#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

static bool ValueSort(pair<char,int>& a,pair<char,int>& b) {
    return a.second>b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<char, int> menu_count;

    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].size(); j++) {
            menu_count[orders[i][j]]++;
        }
    }
    for (auto iter : menu_count) {
        if (iter.second < 2) {
        }
    }
    
    for (auto iter : menu_count) {
        cout << "key : " << iter.first << " value: " << iter.second<<"\n";
    }
    vector<pair<char, int>> course_evaluation(menu_count.begin(), menu_count.end());
    sort(course_evaluation.begin(), course_evaluation.end(), ValueSort);
    while (course_evaluation.back().second == 1) {
        course_evaluation.pop_back();
    }
    cout << "after sort \n";
    for (auto iter : course_evaluation) {
        cout << "key : " << iter.first << " value: " << iter.second << "\n";
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << '"' << answer[i]<<'"';
    }
    string temp = " ";
    for (auto const& coursesize : course) {
        while (temp.size() != coursesize) {

        }
    }

    for (auto const& orderlist : orders) {
        if (orderlist.find(course_evaluation[0].first)) {

        }
    }


    return answer;
}

//testcase
//orders(string[])
//["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
//course(int[])
//[2, 3, 4]
//return
//["AC", "ACDE", "BCFG", "CDE"]

int main() {
    string str = "";
    vector<string> orders;
    while (str != "0") {
        cin >> str;
        orders.push_back(str);
    }
    str = "";
    int num=99;
    vector<int> course;
    while (num != 0) {
        cin >> num;
        course.push_back(num);
    }
    
    solution(orders, course);
    
    return 0;
}