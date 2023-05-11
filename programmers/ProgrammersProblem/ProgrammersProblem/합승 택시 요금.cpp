#include <string>
#include <vector>
#include <queue>

#include <iostream>
using namespace std;


#define MAX 100
#define INF 999999

vector<int> dijkstra(int start, int V, vector < pair<int, int>> adj[]) {
	vector<int> dist(V, INF); //INF로 전체 초기화
	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;	//방문한 정점의 dist 값
		int cur = pq.top().second;	//현재 방문한 정점
		pq.pop();

		for (int i = 0; i < adj[cur].size(); i++) {	//현재 방문한 정점의 주변 정점 모두 탐색
			int next = adj[cur][i].first;			//조사할 다음 정점
			int nCost = cost + adj[cur][i].second;	//현재 방문한 정점을 거쳐서 다음 정점을 갈때의 비용
			if (nCost < dist[next]) {				//기존 비용 보다 현재 방문한 정점을 거친 비용이 더 싸다면
				dist[next] = nCost;					//갱신
				pq.push(make_pair(-nCost, next));	//pq에 저장
			}
		}
	}

	return dist;
}


//n 정점의 갯수 1~n까지
//s 출발지점
//a A도착지점
//b B도착지점
//fares 각 정점과 요금[정점,정점,코스트];
//return s에서 출발 각각 도착지점까지 택시를 타고가는 최소비용
//if합승을 안하고 각자 이동하는 경우 예상 택시요금이 더 낮으면 합승을 하지 않음
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;




	return answer;
}

//입출력 예
//n	s	a	b	fares	result
//6	4	6	2 [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]] 82
//7	3	4	1 [[5, 7, 9], [4, 6, 4], [3, 6, 1], [3, 2, 3], [2, 1, 6]] 14
//6	4	5	6 [[2, 6, 6], [6, 3, 7], [4, 6, 7], [6, 5, 11], [2, 5, 12], [5, 3, 20], [2, 4, 8], [4, 3, 9]] 18

int main() {
	int n, s, a, b;
	vector<vector<int>> fares;

	cin >> n>>s>>a>>b;

	int num;
	while (num != 0) {
		int start, end, cost;
		vector<int> graph;
		cout << "그래프 입력 [정점,정점,비용]\n";
		cin >> start >> end >> cost;
		graph.push_back(start);
		graph.push_back(end);
		graph.push_back(cost);

		fares.push_back(graph);
		if (start == 0 || end == 0 || cost == 0) {
			num = 0;
		}
	}

}