#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> str = { "zero","one","two","three","four","five","six","seven","eight","nine" };
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            temp += s[i];
        }
        else {
            for (int j = 0; j < str.size(); j++) {
                if (0 == str[j].compare(s.substr(i, str[j].size()))) {
                    i += str[j].size() - 1;
                    temp += to_string(j);
                    break;
                }
            }
        }
    }
    answer = stoi(temp);
    return answer;

}