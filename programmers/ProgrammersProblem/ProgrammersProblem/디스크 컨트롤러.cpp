#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    queue<pair<int, int>> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pair<int, int> cur_job = { 0,0 };
    int answer = 0;
    int cur_time = 0, sum = 0;

    sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b)->bool {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });

    for (auto i : jobs) {
        q.push(make_pair(i[0], i[1]));

        if (cur_job.second == 0) {
            cur_job = q.front();
        }
        else {
            if (q.front().first <= cur_job.second + cur_time) {
                pq.push(q.front());
            }
            else {
                if (cur_time > cur_job.first) {
                    cur_time += cur_job.second;
                }
                else {
                    cur_time = cur_job.first + cur_job.second;
                }
                sum += cur_time - cur_job.first;

                if (pq.empty()) {
                    cur_job = q.front();
                }
                else {
                    cur_job = pq.top();
                    pq.pop();
                    pq.push(q.front());
                }
            }
        }
        q.pop();
    }

    while (!pq.empty()) {
        if (cur_time > cur_job.first) {
            cur_time += cur_job.second;
        }
        else {
            cur_time = cur_job.first + cur_job.second;
        }

        sum += cur_time - cur_job.first;
        cur_job = pq.top();
        pq.pop();
    }


    if (pq.empty()) {
        if (cur_time > cur_job.first) {
            cur_time += cur_job.second;
        }
        else {
            cur_time = cur_job.first + cur_job.second;
        }

        sum += cur_time - cur_job.first;
    }

    answer = sum / jobs.size();

    return answer;
}