#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> mapset;
    int max = nums.size() / 2;
    for (auto item : nums) {
        mapset[item]++;
    }

    for (auto iter : mapset) {
        if (max > answer) {
            answer++;
        }
        else break;
    }

    return answer;
}