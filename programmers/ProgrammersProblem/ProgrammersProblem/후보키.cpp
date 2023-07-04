#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int column = relation.size();
    int row = relation[0].size();

    vector<vector<string>> vec(row, vector<string>(column));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            vec[i][j] = relation[j][i];
        }
    }
    for (auto i : vec) {
        sort(i.begin(), i.end(), [](string a, string b)->bool {
            return a.length() < b.length();
        });
        i.erase(unique(i.begin(), i.end()), i.end());
    }
    for (auto i : vec) {
        if (i.size() == column) answer++;
    }

    return answer;
}
