#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//map�� ������ ������ vector�� �̿��� map value���� ������������ �����Ͽ� �ּҰ����� ����
bool mapcomp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    else return a.second > b.second;

}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int count = 0;
    map<int, int> mymap;
    for (const auto& list : tangerine) {
        mymap[list] += 1;
    }
    vector<pair<int, int>> temp(mymap.begin(), mymap.end());
    sort(temp.begin(), temp.end(), mapcomp);

    for (auto num : temp) {
        count += num.second;
        answer++;
        if (count >= k) {
            break;
        }

    }
    return answer;
}