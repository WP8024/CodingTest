#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    stack<int> temp;
    sort(people.begin(), people.end());
    int num = 0;
    for (auto i : people) {
        if (temp.size() > 0 && temp.top() + i <= limit) {
            num = temp.top() + i;
            temp.pop();
            temp.push(num);
        }
        else {
            temp.push(i);
            answer++;
        }
    }

    return answer;
}