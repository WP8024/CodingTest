#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, set<string>> m;
    vector<int> vec;

    for (auto i : clothes) {
        m[i[1]].insert(i[0]);
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        vec.push_back(iter->second.size());
    }

    for (auto i : vec) {
        answer *= i + 1; // ���Դ� ������ �߰�
    }

    return answer - 1;
}