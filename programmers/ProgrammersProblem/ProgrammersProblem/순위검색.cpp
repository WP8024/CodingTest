#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct ApplyData {
    string language = " ";
    string jop = " ";
    string rank = " ";
    string food = " ";
    int score = 0;
};

bool scoreSort(ApplyData& a, ApplyData& b) {
    return a.score > b.score;
}
bool isPass(ApplyData& a, ApplyData& b) {
    if (a.language == b.language && a.jop == b.jop && a.rank == b.rank && a.food == b.food) {
        return a.score > b.score;
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<ApplyData> apply;
    ApplyData temp;

    for (auto list : info) {
        stringstream ss(list);
        vector<string> words;

        string word;
        while (getline(ss, word, ' ')) {
            words.push_back(word);
        }
        temp.language = words[0];
        temp.jop = words[1];
        temp.rank = words[2];
        temp.food = words[3];
        temp.score = stoi(words[4]);
        apply.push_back(temp);
    }

    sort(apply.begin(), apply.end(), scoreSort);


    for (auto const& list : query) {
        stringstream ss(list);
        vector<string> words;

        string word;
        while (getline(ss, word, ' ')) {
            if (word != "and") {
                words.push_back(word);
            }
        }

        temp.language = words[0];
        temp.jop = words[1];
        temp.rank = words[2];
        temp.food = words[3];
        temp.score = stoi(words[4]);
        int num = 0;

        for (int i = 0; i < apply.size(); i++) {
            if (apply[i].score < temp.score) {
                break;
            }
            if ((apply[i].language == temp.language || temp.language == "-") && (apply[i].jop == temp.jop || temp.jop == "-") && (apply[i].rank == temp.rank || temp.rank == "-") && (apply[i].food == temp.food || temp.food == "-") && (apply[i].score >= temp.score)) num++;
        }
        answer.push_back(num);
    }


    return answer;
}