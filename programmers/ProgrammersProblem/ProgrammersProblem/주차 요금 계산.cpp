#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<string, int> m1;
    map<string, string> m2;
    for (auto str : records) {
        vector<string> vec;
        int cur_pos = 0, pos = 0;
        while ((pos = str.find(' ', cur_pos)) != string::npos) {
            int len = pos - cur_pos;
            vec.push_back(str.substr(cur_pos, len));
            cur_pos = pos + 1;
        }
        vec.push_back(str.substr(cur_pos));
        if (vec[2] == "IN") {
            m2[vec[1]] = vec[0];
        }
        if (vec[2] == "OUT") {
            int n1 = (stoi(m2[vec[1]].substr(0, 2)) * 60) + stoi(m2[vec[1]].substr(3));
            int n2 = (stoi(vec[0].substr(0, 2)) * 60) + stoi(vec[0].substr(3));
            m1[vec[1]] += (n2 - n1);
            m2.erase(vec[1]);
        }
    }

    for (auto iter = m2.begin(); iter != m2.end(); iter++) {
        m1[iter->first] += 1439 - (stoi(m2[iter->first].substr(0, 2)) * 60 + stoi(m2[iter->first].substr(3)));
    }

    for (auto iter = m1.begin(); iter != m1.end(); iter++) {
        cout << iter->first << ":" << iter->second << endl;

        int n = (iter->second - fees[0]);
        if (n < 0) {
            answer.push_back(fees[1]);
        }
        else {
            n = n % fees[2] == 0 ? n / fees[2] * fees[3] : (n / fees[2] + 1) * fees[3];
            n += fees[1];
            answer.push_back(n);
        }
    }

    return answer;
}