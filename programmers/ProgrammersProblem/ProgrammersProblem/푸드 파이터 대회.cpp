#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    int num = 0;
    for (int i = 1; i < food.size(); ++i) {
        num += food[i] / 2;
        temp.resize(num, i + '0');
    }
    answer = temp + "0";
    reverse(temp.begin(), temp.end());
    answer += temp;
    return answer;
}