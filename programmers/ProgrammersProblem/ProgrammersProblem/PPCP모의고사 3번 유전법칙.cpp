#include <string>
#include <vector>

using namespace std;

string fuction(int generation, int num) {
    if (generation == 1) return "Rr";

    string temp = fuction(generation - 1, (num - 1) / 4 + 1);

    if (temp == "RR" || temp == "rr") {
        return temp;
    }
    else {
        if (num % 4 == 0) return "rr";
        else if (num % 4 == 1) return "RR";
        else return "Rr";
    }
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;

    for (auto i : queries) {
        answer.push_back(fuction(i[0], i[1]));
    }

    return answer;
}