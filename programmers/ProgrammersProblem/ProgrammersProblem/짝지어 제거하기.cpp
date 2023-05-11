#include <iostream>
#include<string>
#include<deque>
using namespace std;

int solution2(string s) {
    int temp = -1;
    int count = 0;

    while (s.size() / 2) {
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size()) {
                return 0;
            }
            if (s[temp] == s[i]) {
                count++;
            }
            else if (s[temp] != s[i] || temp == -1) {
                if (count >= 2 && count % 2 == 1) {
                    s.erase(temp, count - 1);
                    temp = -1;
                    count = 0;
                    break;
                }
                else if (count >= 2 && count % 2 == 0) {
                    s.erase(temp, count);
                    temp = -1;
                    count = 0;
                    break;
                }
                else {
                    temp = i;
                }
            }
        }
        if (s.empty()) {
            return 1;
        }
    }
    if (s.empty()) {
        return 1;
    }
    else return 0;
}

int solution3(string s) {
    deque<int> dq_temp;
    int index = 0, temp = 0, count = 0;

    if (s.size() % 2 == 1) {
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            temp = i;
        }
        if (s[temp] == s[i]) {
            count++;
        }
        if (s[temp] != s[i]) {
            if (count >= 2 && count % 2 == 1) {
                dq_temp.push_back(s[temp]);
                temp = i;
                count = 1;
            }
            else if (count >= 2 && count % 2 == 0) {
                temp = i;
                count = 1;
            }
            else {
                dq_temp.push_back(s[temp]);
                temp = i;
                count = 1;
            }
        }
    }

    while (!dq_temp.empty()) {
        if (index == dq_temp.size()) {
            break;
        }
        if (dq_temp.size() % 2 == 1) {
            return 0;
        }
        if (index == 0 || dq_temp[temp] != dq_temp[index]) {
            if (count >= 2 && count % 2 == 0) {
                dq_temp.erase(dq_temp.begin() + index, dq_temp.begin() + count);
                index = 0;
                count = 1;
            }
            else if (count >= 2 && count % 2 == 1) {
                dq_temp.erase(dq_temp.begin() + index, dq_temp.begin() + count - 1);
                index = 0;
                count = 1;
            }
            else {
                temp = index;
                count = 1;
            }
        }
        else if (dq_temp[temp] == dq_temp[index]) {
            count++;
        }
        index++;
    }

    if (dq_temp.empty()) {
        return 1;
    }

}


int solution(string s)
{
    int answer = -1;
    deque<char> temp;

    for (const auto& str : s) {
        temp.push_back(str);
    }

    for (int i = 0; i < temp.size() - 1; i++) {
        if (temp[i] == temp[i + 1]) {
            temp.erase(temp.begin() + i);
            temp.erase(temp.begin() + i);
            i = 0;
        }
    }
    if (temp.empty()) {
        return 1;
    }
    else {
        if (temp[0] == temp[1]) {
            temp.erase(temp.begin());
            temp.erase(temp.begin());
            if (temp.empty()) {
                return 1;
            }
        }
        else return 0;
    }

    return answer;
}