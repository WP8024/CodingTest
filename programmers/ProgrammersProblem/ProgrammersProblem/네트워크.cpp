#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<bool> visited;
int answer = 0;

void DFS(vector<vector<int>>& node, int start) {
    if (visited[start] == true) return;
    visited[start] = true;

    for (int next : node[start]) {
        DFS(node, next);
    }
}



int solution(int n, vector<vector<int>> computers) {

    visited.resize(computers[0].size(), false);
    vector<vector<int>> node(computers[0].size());

    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[0].size(); j++) {
            if (computers[i][j] == 1 && i != j) {
                node[i].push_back(j);
            }
        }
    }

    for (auto i = 0; i < computers.size(); i++) {
        if (visited[i] == false) {
            DFS(node, i);
            answer++;
        }
    }

    return answer;
}