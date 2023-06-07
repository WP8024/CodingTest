#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h = 0;
    sort(citations.begin(), citations.end());
    int start = 0, end = citations.size() - 1;
    while (start != end) {

        if (citations.size() - end > h) {
            end--;
            h = citations[end];
        }
        else if (citations[start] < h) {
            start++;
        }
        if (citations.size() - end >= h && citations[start] <= h) {
            answer = h;
            return answer;
        }
    }

    return answer;
}


int main() {
    solution({ 3,0,6,1,5 });
    return 0;
}