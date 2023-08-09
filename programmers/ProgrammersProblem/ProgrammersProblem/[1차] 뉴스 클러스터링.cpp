#include <string>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

string convert(string s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return tolower(c);
    });
    return s;
}

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> mapset1, mapset2;
    set<string> sset;
    string s = "";
    str1 = convert(str1);
    str2 = convert(str2);

    for (int i = 1; i < str1.size(); i++) {
        if (isalpha(str1[i - 1]) && isalpha(str1[i])) {
            s += str1[i - 1];
            s += str1[i];
            mapset1[s]++;
            sset.insert(s);
            s.clear();
        }
    }
    for (int i = 1; i < str2.size(); i++) {
        if (isalpha(str2[i - 1]) && isalpha(str2[i])) {
            s += str2[i - 1];
            s += str2[i];
            mapset2[s]++;
            sset.insert(s);
            s.clear();
        }
    }


    int sumset = 0, intersection = 0;
    for (auto i : sset) {
        sumset += max(mapset1[i], mapset2[i]);
        intersection += min(mapset1[i], mapset2[i]);
    }

    if (sumset == 0) {
        return 65536;
    }

    answer = (double)intersection / (double)sumset * 65536;
    return answer;
}