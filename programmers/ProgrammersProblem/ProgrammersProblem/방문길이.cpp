#include <string>
#include <set>
#include <iostream>
using namespace std;


struct Point {
    int x, y;

    bool operator<(const Point& var) const {
        if (x != var.x) {
            return x < var.x;
        }
        else {
            return y < var.y;
        }
    }

    Point operator+(const Point& var) const {
        Point temp;
        temp.x = x + var.x;
        temp.y = y + var.y;
        if (temp.x > 5 || temp.x < -5) {
            temp.x = x;
        }
        if (temp.y > 5 || temp.y < -5) {
            temp.y = y;
        }
        return temp;
    }
    bool operator!=(const Point& var) const {
        if (x == var.x && y == var.y) {
            return false;
        }
        return true;
    }
};

static Point pos[] = { {0,1},{0,-1},{-1,0},{1,0} };

class Character {
    Point p;
    set<pair<Point, Point>> s;
public:
    Character(Point _p) {
        this->p = _p;
    }
    void Move(char ch) {
        Point prev = p;
        if (ch == 'U') {
            p = p + pos[0];
        }
        if (ch == 'D') {
            p = p + pos[1];
        }
        if (ch == 'L') {
            p = p + pos[2];
        }
        if (ch == 'R') {
            p = p + pos[3];
        }
        if (p != prev) {
            if (p < prev) {
                s.insert(make_pair(p, prev));
            }
            else {
                s.insert(make_pair(prev, p));
            }
        }
    }

    int getSetSize() {
        return s.size();
    }
};

int solution(string dirs) {
    int answer = 0;
    Point p = { 0,0 };
    Character cha(p);

    for (auto ch : dirs) {
        cha.Move(ch);
    }

    return answer = cha.getSetSize();
}