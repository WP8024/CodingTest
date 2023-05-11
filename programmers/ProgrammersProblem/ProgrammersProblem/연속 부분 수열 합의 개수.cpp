#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> numberlist;
    int e_index = elements.size();
    int temp = 0, count = 0;
    for (int i = 0; i < e_index; i++) {
        for (int j = 0; j < e_index; j++) {
            temp = 0;
            count = 0;
            while (count != i + 1) {
                temp += elements[(j + count) % e_index];
                count++;
            }
            numberlist.push_back(temp);
        }
    }
    sort(numberlist.begin(), numberlist.end());
    numberlist.erase(unique(numberlist.begin(), numberlist.end()), numberlist.end());
    answer = numberlist.size();
    return answer;
}