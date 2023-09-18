#include <string>
#include <vector>

using namespace std;

const int MAX = 1000001;
static vector<int> num(MAX, MAX);

void func(int x, int y, int n, int count) {
    if (x > y || count >= num[y]) return;

    if (num[x] > count) {
        num[x] = count;
        if (x + n <= y) func(x + n, y, n, count + 1);
        if (x * 2 <= y) func(x * 2, y, n, count + 1);
        if (x * 3 <= y) func(x * 3, y, n, count + 1);
    }

    return;
}


int solution(int x, int y, int n) {
    int answer = -1;
    func(x, y, n, 0);
    if (num[y] == MAX) return -1;
    return num[y];
}