#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int curbottle = n;
    int temp = 0;
    while (curbottle >= a) {
        temp = curbottle % a;
        curbottle = (curbottle / a) * b;
        answer += curbottle;
        curbottle += temp;
    }
    return answer;
}