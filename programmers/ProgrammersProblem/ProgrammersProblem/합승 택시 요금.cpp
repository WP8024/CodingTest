#include <string>
#include <vector>
#include <queue>

#include <iostream>
using namespace std;


#define MAX 100
#define INF 999999

vector<int> dijkstra(int start, int V, vector < pair<int, int>> adj[]) {
	vector<int> dist(V, INF); //INF�� ��ü �ʱ�ȭ
	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = -pq.top().first;	//�湮�� ������ dist ��
		int cur = pq.top().second;	//���� �湮�� ����
		pq.pop();

		for (int i = 0; i < adj[cur].size(); i++) {	//���� �湮�� ������ �ֺ� ���� ��� Ž��
			int next = adj[cur][i].first;			//������ ���� ����
			int nCost = cost + adj[cur][i].second;	//���� �湮�� ������ ���ļ� ���� ������ ������ ���
			if (nCost < dist[next]) {				//���� ��� ���� ���� �湮�� ������ ��ģ ����� �� �δٸ�
				dist[next] = nCost;					//����
				pq.push(make_pair(-nCost, next));	//pq�� ����
			}
		}
	}

	return dist;
}


//n ������ ���� 1~n����
//s �������
//a A��������
//b B��������
//fares �� ������ ���[����,����,�ڽ�Ʈ];
//return s���� ��� ���� ������������ �ýø� Ÿ���� �ּҺ��
//if�ս��� ���ϰ� ���� �̵��ϴ� ��� ���� �ýÿ���� �� ������ �ս��� ���� ����
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;




	return answer;
}

//����� ��
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
		cout << "�׷��� �Է� [����,����,���]\n";
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