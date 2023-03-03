#include <string>
#include <vector>
#include <iostream>
#include <cstdlib> //int abs함수 사용을 위해

using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/161990

struct Point {
	int x, y;
};

void Drag(Point S, Point E) {
	int XLength = E.x - S.x;
	int YLength = E.y - S.y;
	XLength = abs(XLength);
	YLength = abs(YLength);
	

	cout << "S:" << S.y << "," << S.x << "E:" << E.y << "," << E.x;
	cout << "\n";
	cout << "XLength" << XLength << "YLength" << YLength << "\n";
}

vector<int> solution(vector<string> wallpaper) {
	int width = wallpaper[0].size();
	int length = wallpaper.size();
	cout << "width:" << width << "length:" << length<<"\n";

	Point S = { 50,50 }, E = { 0,0 };

	cout << "S:" << S.x<< "," <<S.y << "E:" << E.x<<"," << E.y;


	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (wallpaper[i][j] == '#') {
				if (S.y >= i) {
					S.y = i;
				}
				if (E.y <= i + 1) {
					E.y = i + 1;
				}
				if (S.x >= j) {
					S.x = j;
				}
				if (E.x <= j+1) {
					E.x = j + 1;
				}
			}
		}
		cout << "\n";
	}

	vector<int> answer;

	answer.push_back(S.y);
	answer.push_back(S.x);
	answer.push_back(E.y);
	answer.push_back(E.x);

	return answer;
}


int main() {
	cout << "입력할 매트릭스" << "\n";
	cout << "입력완료시 0 입력"<<"\n";

	vector<string> wallpaper;
	
	while (true) {
		string Problem;

		cin >> Problem;
		if (Problem == "0") {
			break;
		}
		else {
			wallpaper.push_back(Problem);
		}
	}

	cout << "입력된 매트릭스" << "\n";

	for (int i = 0; i < wallpaper.size(); i++) {
		cout << '"' << wallpaper[i]<<'"';
	}

	cout << "\n솔루션 함수 시작\n";	
	solution(wallpaper);

	return 0;
}