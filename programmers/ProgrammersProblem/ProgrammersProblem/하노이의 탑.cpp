#include <string>
#include <vector>
using namespace std;

//풀이
//start, sub, end 기둥 3개가 있을때
//start n 을 end로 보내는건
//n이 1인경우 start->end로
//(n-1)개를 sub로 이동
//n번막대를 end로 이동
//(n-1)개를 end로 이동

//recursion을 이용해 풀이
//1번 재귀: n-1개의 원반을 start->sub로
//2번 재귀: n-1개의 원반을 sub->end로

static vector<vector<int>> answer;

vector<int> move(int n, int start, int end) {
    vector<int> temp;
    temp.push_back(start);
    temp.push_back(end);
    return temp;
}

void hanoi(int n, int start, int end, int sub) {
    if (n == 1) {
        answer.push_back(move(1, start, end));
        return;
    }
    else {
        hanoi(n - 1, start, sub, end);
        answer.push_back(move(n, start, end));
        hanoi(n - 1, sub, end, start);
    }
}


vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    return answer;
}