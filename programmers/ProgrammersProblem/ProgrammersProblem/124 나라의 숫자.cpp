#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    vector<char> rule = { '1','2','4' };
    while (n > 0) {
        n--;
        answer += rule[n % 3];
        n /= 3;
    }
    reverse(answer.begin(), answer.end());


    return answer;
}