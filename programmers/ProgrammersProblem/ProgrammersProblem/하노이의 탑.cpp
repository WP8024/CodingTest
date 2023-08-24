#include <string>
#include <vector>
using namespace std;

//Ǯ��
//start, sub, end ��� 3���� ������
//start n �� end�� �����°�
//n�� 1�ΰ�� start->end��
//(n-1)���� sub�� �̵�
//n�����븦 end�� �̵�
//(n-1)���� end�� �̵�

//recursion�� �̿��� Ǯ��
//1�� ���: n-1���� ������ start->sub��
//2�� ���: n-1���� ������ sub->end��

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