#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int priority = 1;
    int temp = 0;
    bool pass = true;
    map<char, int> skillmap;
    for (auto ch : skill) {
        skillmap[ch] = priority;
        priority++;
    }
    for (auto trees : skill_trees) {
        temp = 0;
        pass = true;
        for (auto ch : trees) {
            if (skillmap[ch] != 0 && skillmap[ch] - temp == 1) {
                temp = skillmap[ch];
            }
            else if (skillmap[ch] != 0 && skillmap[ch] - temp != 0) {
                pass = false;
                break;
            }
        }
        if (pass) {
            answer++;
        }
    }


    return answer;
}