#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int s = 0;

    for (int i = 1; i <= n; i++) {
        if (s < stations.size() && i >= stations[s] - w) {
            i = stations[s] + w;
            s++;
        }
        else {
            answer++;
            i += w * 2;
        }
    }

    return answer;
}