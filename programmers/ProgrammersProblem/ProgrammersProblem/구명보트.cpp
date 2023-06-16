#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int num = 0;
    int start = 0, end = people.size() - 1;

    while (1) {
        if (start > end) {
            break;
        }
        if (people[start] + people[end] <= limit) {
            start++;
            end--;
            answer++;
        }
        else {
            end--;
            answer++;
        }
    }

    return answer;
}