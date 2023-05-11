#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string binary(int a) {
    string s_temp;
    int i_temp;
    while (a != 0) {
        s_temp += to_string(a % 2);
        a /= 2;
    }
    reverse(s_temp.begin(), s_temp.end());

    return s_temp;
}

vector<int> solution(string s) {
    vector<int> answer;
    int repeat = 0, erase = 0;
    int i_temp;
    string s_temp;
    char ch = '0';

    while (s.size() != 1) {
        i_temp = count(s.begin(), s.end(), ch);
        erase += i_temp;
        s_temp.resize(s.size() - i_temp, 1);
        s = s_temp;
        s_temp.clear();
        s = binary(s.size());
        repeat++;
    }
    answer.push_back(repeat);
    answer.push_back(erase);
    return answer;
}