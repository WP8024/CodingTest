#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> wordset;
    int count = 1, temp;
    string lastword = "";
    for (auto str : words) {

        if (!lastword.empty() && (wordset[str] != 0 || lastword.back() != str.front())) {
            temp = count % n;
            if (temp == 0) {
                temp = n;
                answer.push_back(temp);
                answer.push_back(count / n);
            }
            else {
                answer.push_back(temp);
                answer.push_back(count / n + 1);
            }
            break;
        }
        else {
            wordset[str]++;
            count++;
            lastword = str;
        }
    }
    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}