#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int temp = n / 2;
    for (int i = 0; i < n / 2; i++) {
        answer += "����";
    }
    if (n % 2 == 1) {
        answer += "��";
    }
    return answer;
}