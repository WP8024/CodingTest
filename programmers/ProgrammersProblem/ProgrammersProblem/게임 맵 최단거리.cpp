#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> vec;
vector<vector<bool>> visited;
vector<int> row = { 1,0,-1,0 }, column = { 0,1,0,-1 };

void BFS(vector<vector<int>>& m, pair<int, int> pos) {
    queue<pair<int, int>> q;
    q.push(pos);
    visited[pos.first][pos.second] = true;

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = temp.first + row[i];
            int ncolumn = temp.second + column[i];

            if (nrow < 0 || ncolumn < 0 || nrow >= m.size() || ncolumn >= m[0].size() || m[nrow][ncolumn] == 0 || visited[nrow][ncolumn]) continue;

            vec[nrow][ncolumn] = min(vec[nrow][ncolumn], vec[temp.first][temp.second] + 1);

            visited[nrow][ncolumn] = true;

            if (nrow == m.size() - 1 && ncolumn == m[0].size() - 1) return;

            q.push(make_pair(nrow, ncolumn));
        }

    }
    return;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int y = maps.size();
    int x = maps[0].size();

    vec.resize(y, vector<int>(x, 10000));
    visited.resize(y, vector<bool>(x, false));
    vec[0][0] = 1;

    BFS(maps, { 0,0 });

    answer = vec[y - 1][x - 1];
    if (!visited[y - 1][x - 1]) answer = -1;

    return answer;
}