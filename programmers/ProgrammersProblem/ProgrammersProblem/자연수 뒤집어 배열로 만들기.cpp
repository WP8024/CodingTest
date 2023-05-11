#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string temp = to_string(n);
    reverse(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++) {
        answer.push_back(temp[i] - '0');
    }

    return answer;
}