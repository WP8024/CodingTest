#include <string>
#include <vector>

using namespace std;
//n�� ���� num%2
//���� t���� string size
//�����ο� m
//Ʃ�� ����p
//�ʿ��� ��ü ���ڿ� ������= t*m+p
string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<char> numlist = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
    int index = 1, count = 1, num = 0;
    string str = "0";
    if (p == 1) {
        answer += '0';
    }
    while (answer.size() < t) {
        num = index;
        while (num != 0) {
            count++;
            str += numlist[num % n];
            if (count % m == p || (m == p && count % m == 0)) {
                answer += numlist[num % n];
            }
            num /= n;
        }
        index++;
    }
    return answer;
}
