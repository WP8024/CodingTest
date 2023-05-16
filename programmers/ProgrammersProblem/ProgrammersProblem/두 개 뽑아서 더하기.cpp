#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int size = numbers.size();
    int sum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            sum = numbers[i] + numbers[j];
            answer.push_back(sum);
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}