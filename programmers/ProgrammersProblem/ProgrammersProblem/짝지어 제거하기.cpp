#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = -1;
    vector<char> list;
    for (auto ch : s) {
        if (list.size() > 0 && list.back() == ch) {
            list.pop_back();
        }
        else {
            list.push_back(ch);
        }
    }
    if (list.empty()) {
        answer = 1;
    }
    else {
        answer = 0;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}