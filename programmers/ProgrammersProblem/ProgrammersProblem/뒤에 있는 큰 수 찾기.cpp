#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int start = 0;
    for (int i = 0; start < numbers.size(); i++) {
        if (i == numbers.size()) {
            answer.push_back(-1);
            start++;
            i = start;
        }
        if (numbers[start] < numbers[i]) {
            answer.push_back(numbers[i]);
            start++;
            i = start;
        }
    }
    return answer;
}