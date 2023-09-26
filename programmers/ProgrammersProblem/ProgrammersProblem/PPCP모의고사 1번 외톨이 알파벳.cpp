#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string input_string) {
    string answer = "";
    map<char, int> m;
    vector<bool> alpha('z' - 'a' + 1, false);
    int index = 0;
    for (int i = 0; i < input_string.size(); i++) {
        char temp = input_string[i];
        if (alpha[temp - 'a'] == false) {
            m[temp]++;
            while (input_string[i + 1] == temp && i + 1 < input_string.size()) {
                i++;
            }
            if (m[temp] > 1) {
                alpha[temp - 'a'] = true;
                answer += temp;
            }
        }
    }

    if (answer.empty()) {
        answer = "N";
    }
    else {
        sort(answer.begin(), answer.end());
    }

    return answer;
}