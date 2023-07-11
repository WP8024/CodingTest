#include <string>
#include <vector>

using namespace std;
//��ȭ������ ���ϸ� ���� �ذ�
//n=1�϶� 1 n=2�϶� 2 n=3�϶� 3 n=4�϶� 5
//n=n-1+n-2����
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