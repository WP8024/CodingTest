#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Sentence {
    string head;
    string number;
    int Inum;
    string tail;
    string lhead;
};

bool operator<(const Sentence& a, const Sentence& b) {
    if (a.lhead == b.lhead) {
        return a.Inum < b.Inum;
    }

    return a.lhead < b.lhead;
}

string lower(string a) {
    transform(a.begin(), a.end(), a.begin(), [](char c) {
        return tolower(c);
    });
    return a;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<string> tag(3, "");
    vector<Sentence> list;
    Sentence temp;

    for (auto str : files) {
        tag = vector<string>(3, "");
        for (int i = 0; i < str.size(); i++) {
            if (tag[0].empty() && isdigit(str[i])) {
                tag[0] = str.substr(0, i);
                tag[1] += str[i];
            }
            else if (!tag[0].empty() && !isdigit(str[i])) {
                tag[2] = str.substr(i);
                break;
            }
            else if (tag[2].empty() && isdigit(str[i])) {
                tag[1] += str[i];
            }
        }
        temp.head = tag[0];
        temp.number = tag[1];
        temp.tail = tag[2];
        temp.Inum = stoi(tag[1]);
        temp.lhead = lower(tag[0]);
        list.push_back(temp);
    }

    stable_sort(list.begin(), list.end());

    for (auto str : list) {
        answer.push_back(str.head + str.number + str.tail);
    }
    return answer;
}
