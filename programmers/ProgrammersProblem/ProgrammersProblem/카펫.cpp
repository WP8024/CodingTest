#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int colum = 0, row = 0;
    int total = brown + yellow;

    for (int i = 2; i <= total / 2; i++) {
        if (total % i == 0) {
            colum = i;
            row = total / colum;
            if ((row + colum - 2) * 2 == brown) {
                answer.push_back(row);
                answer.push_back(colum);
                return answer;
            }
        }
    }
    return answer;
}