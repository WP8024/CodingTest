#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> se;

    for (auto str : phone_book) {
        for (int i = 1; i < str.size(); i++) {
            se.insert(str.substr(0, i));
        }
    }
    for (auto str : phone_book) {
        if (se.find(str) != se.end()) {
            return false;
        }
    }
    return answer;
}