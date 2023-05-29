#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, float> a, const pair<int, float> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, int> mapset, total;
    map<int, double> pass;
    for (const auto& item : stages) {
        mapset[item]++;
        for (int i = 1; i <= item; i++) {
            total[i]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        pass[i] = (double)mapset[i] / total[i];
    }

    vector<pair<int, double>> temp(pass.begin(), pass.end());
    //sort�� �ҽ� �׽�Ʈ ����� �ȵ�
    //sort�� ���������� quick sort 
    //stable sort�� ���������� merge sort ����̴�
    //���� �˰��� �� �����Ͱ� ������ ID(key)�� �̷���� ��� sort()����� ����� �ٸ��� ���� �� �ִ�.
    //stable�� ���� ������ �����ϴ� ���η� �Ǻ��ȴ�. 
    //unstable:selection,quick,heap sort
    //stable:merge sort
    stable_sort(temp.begin(), temp.end(), cmp); 

    for (auto iter = temp.begin(); iter != temp.end(); ++iter) {
        answer.push_back(iter->first);
    }

    return answer;
}