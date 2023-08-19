#include <string>
#include <vector>
#include <map>
using namespace std;

static map<int, int> m;
struct point {
    int x, y;
};

void func(vector<vector<int>>& arr, int size, point p) {
    if (size == 1) {
        m[arr[p.x][p.y]]++;
        return;
    }

    int temp = arr[p.x][p.y];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i + p.x][j + p.y] != temp) {
                func(arr, size / 2, p);
                func(arr, size / 2, { p.x + size / 2,p.y });
                func(arr, size / 2, { p.x,p.y + size / 2 });
                func(arr, size / 2, { p.x + size / 2,p.y + size / 2 });
                return;
            }
        }
    }
    m[temp]++;

    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int n = arr.size();
    point p = { 0,0 };
    func(arr, n, p);

    answer.push_back(m[0]);
    answer.push_back(m[1]);
    return answer;
}