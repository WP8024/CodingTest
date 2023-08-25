#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<char> numlist = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

    int c_num = 0;
    int count = 0;
    string str = "";

    while (answer.size() < t) {
        int num = c_num;

        while (num > 0) {
            str += numlist[num % n];
            num /= n;
        }

        if (str.empty()) {
            str = '0';
        }
        else {
            reverse(str.begin(), str.end());
        }

        for (auto ch : str) {
            count++;
            if (count % m == p % m) {
                answer += ch;
            }
        }
        str.clear();
        c_num++;
    }

    answer = answer.substr(0, t);
    return answer;
}