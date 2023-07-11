#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Energy {
    int cost;
    int requirement;
};

bool operator<(const Energy& a, const Energy& b) {
    if (a.cost == b.cost) {
        return a.requirement > b.requirement;
    }
    return a.cost < b.cost;

    if (a.requirement == b.requirement) {
        return a.cost < b.cost;
    }
    return a.requirement > b.requirement;
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<Energy> list;
    Energy temp;
    stack<Energy> st;



    for (auto i : dungeons) {
        temp.cost = i[1];
        temp.requirement = i[0];
        list.push_back(temp);
    }



    for (auto i : list) {
        if (!st.empty()) {
            int cost1 = k - st.top().cost;
            int cost2 = k - i.cost;
            if (cost1 >= cost2 && k >= st.top().requirement) {
                st.pop();
                st.push(i);
                answer++;
                k = cost1;
            }
            else if (cost1 < cost2 && k >= i.requirement) {
                k = cost2;
                answer++;
            }
            else {
                while (!st.empty()) {
                    if (st.top().requirement > k) {
                        st.pop();
                    }
                    else {
                        break;
                    }
                }
            }
        }
        else {
            st.push(i);
        }
    }

    return answer;
}