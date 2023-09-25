#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<string> answer = { "ICN" };
int count = 0;

bool DFS(map<string, multiset<string>>& m, string start, int count, int end) {
    if (count == end) return true;

    for (auto iter = m[start].begin(); iter != m[start].end();) {
        answer.push_back(*iter);
        string temp = *iter;
        iter = m[start].erase(iter);
        bool pass = DFS(m, temp, count + 1, end);

        if (!pass) {
            m[start].insert(temp);
            answer.pop_back();
        }
        else {
            return true;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {

    map<string, multiset<string>> m;

    for (auto str : tickets) {
        m[str[0]].insert(str[1]);
    }
    DFS(m, "ICN", 0, tickets.size());

    return answer;
}