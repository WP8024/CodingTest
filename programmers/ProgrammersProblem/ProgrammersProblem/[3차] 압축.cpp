#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> mapset;
    int num = 1;
    string str;
    for (int i = 0; i < 26; i++) {
        char ch = 'A' + i;
        str += ch;
        mapset[str] = num;
        num++;
        str.clear();
    }
    string w, c;

    for (int i = 0; i < msg.size(); i++) {
        w += msg[i];
        if (i + 1 < msg.size()) {
            c = msg[i + 1];
        }
        if (mapset[w + c] == 0 || i + 1 == msg.size()) {
            answer.push_back(mapset[w]);
            mapset[w + c] = num;
            num++;
            w.clear();
        }

    }

    return answer;
}