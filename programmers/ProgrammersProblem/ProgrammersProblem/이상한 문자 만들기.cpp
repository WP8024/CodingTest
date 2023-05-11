#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp;
    vector<string> words;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        if (*iter == ' ') {
            words.push_back(temp);
            temp = "";
        }
        else {
            temp += *iter;
        }
        if (iter == s.end() - 1) {
            words.push_back(temp);
        }
    }
    for (auto word : words) {
        for (int i = 0; i < word.size(); i++) {
            if (i % 2 == 0) {
                word[i] = toupper(word[i]);
            }
            else {
                word[i] = tolower(word[i]);
            }
        }
        answer += word + " ";
    }
    answer.pop_back();
    return answer;
}