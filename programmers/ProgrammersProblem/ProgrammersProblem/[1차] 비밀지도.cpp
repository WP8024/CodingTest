#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string binary(int n) {
    string str;
    while (n != 0) {
        str += to_string(n % 2);
        n /= 2;
    }
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> map1, map2;
    string temp;
    for (const auto num : arr1) {
        temp = binary(num);
        temp.resize(n, '0');
        reverse(temp.begin(), temp.end());
        map1.push_back(temp);
    }
    for (const auto num : arr2) {
        temp = binary(num);
        temp.resize(n, '0');
        reverse(temp.begin(), temp.end());
        map2.push_back(temp);
    }
    answer = map1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map1[i][j] == '1' || map2[i][j] == '1') {
                answer[i][j] = '#';
            }
            else {
                answer[i][j] = ' ';
            }
        }
    }

    return answer;
}