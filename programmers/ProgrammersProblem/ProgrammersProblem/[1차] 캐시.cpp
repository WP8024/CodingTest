#include <string>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    set<string> se;
    deque<string> deq;

    for (auto str : cities) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if (se.find(str) != se.end()) {
            answer += 1;
            deq.push_back(str);
            if (deq.size() > cacheSize || find(deq.begin(), deq.end(), str) != deq.end()) {
                deq.erase(find(deq.begin(), deq.end(), str));
            }
        }
        else {
            answer += 5;
            se.insert(str);
            deq.push_back(str);
            if (deq.size() > cacheSize) {
                se.erase(deq.front());
                deq.pop_front();
            }
        }
    }

    return answer;
}