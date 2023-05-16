#include <string>
#include <vector>
#include <algorithm>

using namespace std;
static int index;
bool indexcomp(string a, string b) {
    if (a[index] == b[index]) {
        return a < b;
    }
    return a[index] < b[index];
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    index = n;
    sort(strings.begin(), strings.end(), indexcomp);
    answer = strings;
    return answer;
}