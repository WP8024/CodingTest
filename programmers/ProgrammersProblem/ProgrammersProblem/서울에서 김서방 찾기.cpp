#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int index;
    string str;
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            index = i;
        }
    }
    str = to_string(index);
    answer = "�輭���� " + str + "�� �ִ�";
    return answer;
}