#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int size = number.size();
    int sum = 0;
    map<int, int> total;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int l = j + 1; l < size; l++) {
                sum = number[i] + number[j] + number[l];
                total[sum]++;
            }
        }
    }
    answer = total[0];
    return answer;
}