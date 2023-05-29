#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool primelist[1000001];
    vector<int> prime;

    for (int i = 0; i < 1000000; i++) {
        primelist[i] = true;
    }

    for (int i = 2; i <= 1000000; i++) {
        if (primelist[i] == true) {
            prime.push_back(i);
            for (int j = 2; j * i <= 1000000; j++) {
                if (primelist[j * i] == true) {
                    primelist[j * i] = false;
                }
            }
        }
    }

    for (auto index : prime) {
        if (index <= n) {
            answer++;
        }
        else break;
    }

    return answer;
}