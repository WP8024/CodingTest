#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> mapset;
    int count = 10;
    bool check = false;

    for (int i = 0; i < want.size(); i++) {
        mapset[want[i]] = number[i];
    }

    for (int i = 0; i < discount.size(); i++) {
        if (i < count) {
            mapset[discount[i]]--;
        }
        else {
            mapset[discount[i - count]]++;
            mapset[discount[i]]--;
        }

        if (mapset[discount[i]] <= 0) {
            check = true;
            for (auto iter : mapset) {
                if (iter.second > 0) {
                    check = false;
                    break;
                }
            }
            if (check == true) {
                answer++;
            }
        }
    }

    return answer;
}