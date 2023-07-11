#include <string>
#include <vector>

using namespace std;
//점화식으로 구하면 쉽게 해결
//n=1일때 1 n=2일때 2 n=3일때 3 n=4일때 5
//n=n-1+n-2형태
int solution(int n) {
    int answer = 0;
    vector<int> vec(n + 1, 0);
    vec[1] = 1;
    vec[2] = 2;
    for (int i = 3; i <= n; i++) {
        vec[i] = (vec[i - 2] + vec[i - 1]) % 1000000007;
    }

    answer = vec[n];

    return answer;
}