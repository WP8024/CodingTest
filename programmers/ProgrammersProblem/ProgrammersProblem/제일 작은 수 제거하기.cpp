#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b) {
    return a > b;
}
vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }
    auto temp = arr.begin();
    int min = 9999999;
    for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
        if (*iter <= min) {
            min = *iter;
            temp = iter;
        }
    }

    arr.erase(temp);
    answer = arr;
    return answer;
}