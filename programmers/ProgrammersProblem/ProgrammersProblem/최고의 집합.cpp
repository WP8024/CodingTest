#include <string>
#include <vector>

using namespace std;

void func(int n, int s, vector<int>& a) {
    if (n > s) {
        a.clear();
        a.push_back(-1);
        return;
    }
    if (n == 1) {
        a.push_back(s);
        return;
    }

    int m = s / n;
    a.push_back(m);
    func(n - 1, s - m, a);
    return;
}

vector<int> solution(int n, int s) {
    vector<int> answer;

    func(n, s, answer);

    return answer;
}