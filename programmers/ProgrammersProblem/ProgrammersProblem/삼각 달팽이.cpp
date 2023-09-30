#include <string>
#include <vector>
using namespace std;

void func(vector<vector<int>>& vec, int n, int count, int y, int x, int num) {
    if (n == 1) {
        num++;
        vec[y][x] = num;
        return;
    }

    int newx = x;
    int newy = y;

    if (count % 3 == 1) {
        for (int i = 0; i < n; i++) {
            newy = y + i;
            num++;
            vec[newy][newx] = num;
        }
        newx++;
    }
    if (count % 3 == 2) {
        for (int i = 0; i < n; i++) {
            newx = x + i;
            num++;
            vec[newy][newx] = num;
        }
        newx--;
        newy--;
    }
    if (count % 3 == 0) {
        for (int i = 0; i < n; i++) {
            newx = x - i;
            newy = y - i;
            num++;
            vec[newy][newx] = num;
        }
        newy++;
    }

    func(vec, n - 1, count + 1, newy, newx, num);
    return;
}

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i].resize(i + 1);
    }
    func(vec, n, 1, 0, 0, 0);

    for (auto i : vec) {
        answer.insert(answer.end(), i.begin(), i.end());
    }

    return answer;
}