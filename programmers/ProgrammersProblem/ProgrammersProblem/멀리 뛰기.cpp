#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> move = { 1,2 };
    int temp = 0;
    int arr[2001] = { 0, };
    arr[0] = 1, arr[1] = 2;
    for (int i = 2; i < 2001; i++) {
        arr[i] = (arr[i - 2] + arr[i - 1]) % 1234567;
    }
    answer = arr[n - 1];
    return answer;
}