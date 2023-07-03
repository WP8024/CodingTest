#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int storey) {
    int answer = 0;

    string temp = to_string(storey);
    reverse(temp.begin(), temp.end());
    vector<int> vec(temp.size() + 1, 0);

    for (int i = 0; i < temp.size(); i++) {
        int t = temp[i] - '0';
        vec[i] = t;
    }

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > 5) {
            answer += 10 - vec[i];
            vec[i + 1]++;
        }
        else if (vec[i] == 5) {
            answer += vec[i];
            if (vec[i + 1] >= 5) {
                vec[i + 1]++;
            }
        }
        else {
            answer += vec[i];
        }
    }


    return answer;
}