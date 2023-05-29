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
    //sort로 할시 테스트 통과가 안됨
    //sort는 내부적으로 quick sort 
    //stable sort는 내부적으로 merge sort 방식이다
    //정렬 알고리즘 중 데이터가 동일한 ID(key)로 이루어진 경우 sort()결과가 예상과 다르게 나올 수 있다.
    //stable은 원소 순서를 보장하는 여부로 판별된다. 
    //unstable:selection,quick,heap sort
    //stable:merge sort
    stable_sort(temp.begin(), temp.end(), cmp); 

    for (auto iter = temp.begin(); iter != temp.end(); ++iter) {
        answer.push_back(iter->first);
    }

    return answer;
}