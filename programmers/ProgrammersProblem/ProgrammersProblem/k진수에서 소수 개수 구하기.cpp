#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string convert(int n, int k) {
    string temp = "";

    while (n != 0) {
        int t = n % k;
        temp += t + '0';
        n /= k;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

bool isPrime(long long n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string temp = convert(n, k);

    vector<string> vec;
    string str = "";

    for (auto ch : temp) {
        if (ch == '0' && str.size() > 0) {
            if (str != "1") {
                vec.push_back(str);
            }
            str = "";
        }
        else if (ch == '0') {

        }
        else {
            str += ch;
        }
    }

    if (!str.empty() && str != "1") {
        vec.push_back(str);
    }

    if (vec.empty()) {
        return answer;
    }
    for (auto i : vec) {
        if (isPrime(stoll(i))) {
            answer++;
        }
    }

    return answer;
}