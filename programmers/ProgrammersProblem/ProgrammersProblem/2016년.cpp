#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(int a, int b) {
    int month[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    string day[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
    string answer = "";

    int temp = 0;
    for (int i = 0; i < a - 1; ++i) {
        temp += month[i];
    }
    temp = (temp + b + 4) % 7;
    answer = day[temp % 7];
    return answer;
}