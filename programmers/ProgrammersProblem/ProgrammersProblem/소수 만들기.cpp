#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    bool primelist[3001];
    vector<int> prime, sum;
    for (int i = 0; i < 3000; i++) {
        primelist[i] = true;
    }
    for (int i = 2; i <= 3000; i++) {
        if (primelist[i] == true) {
            prime.push_back(i);
            for (int j = 2; i * j <= 3000; j++) {
                primelist[i * j] = false;
            }
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int l = j + 1; l < nums.size(); l++) {
                sum.push_back(nums[i] + nums[j] + nums[l]);
            }
        }
    }

    for (int i = 0; i < sum.size(); i++) {
        if (find(prime.begin(), prime.end(), sum[i]) != prime.end()) {
            answer++;
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}