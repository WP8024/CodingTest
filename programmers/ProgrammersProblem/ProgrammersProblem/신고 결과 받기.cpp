#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    multimap<string, string> m_map;
    map<string, int> m;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    int index = 0;

    for (auto id : report) {
        index = id.find(' ');
        m_map.insert(make_pair(id.substr(index + 1), id.substr(0, index)));
    }

    for (auto id : id_list) {
        if (m_map.count(id) >= k) {
            for (auto iter = m_map.lower_bound(id); iter != m_map.upper_bound(id); iter++) {
                m[iter->second]++;
            }
        }
    }
    for (auto id : id_list) {
        answer.push_back(m[id]);
    }

    return answer;
}