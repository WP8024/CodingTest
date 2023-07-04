#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    multiset<int>::iterator iter;

    for (auto i : operations) {
        if (i[0] == 'I') ms.insert(stoi(i.substr(1)));
        else {
            if (stoi(i.substr(1)) == 1) {
                if (ms.size() != 0) ms.erase(--ms.end());
            }
            else {
                if (ms.size() != 0) ms.erase(ms.begin());

            }

        }
    }
    if (ms.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        iter = --ms.end();
        answer.push_back(*iter);
        iter = ms.begin();
        answer.push_back(*iter);
    }
    return answer;
}