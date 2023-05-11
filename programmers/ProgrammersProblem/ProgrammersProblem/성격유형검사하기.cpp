#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {

    map<char, int> seat;
    string answer = "";

    for (int i = 0; i < survey.size(); i++) {

        if (choices[i] < 4) {
            seat[survey[i][0]] += 4 - choices[i];
        }
        else if (choices[i] > 4) {
            seat[survey[i][1]] += choices[i] - 4;
        }
    }
    
    if (seat['R'] < seat['T']) answer += 'T';
    else answer += 'R';
  
    if (seat['C'] < seat['F']) answer += 'F';
    else answer += 'C';

    if (seat['J'] < seat['M']) answer += 'M';
    else answer += 'J';

    if (seat['A'] < seat['N']) answer += 'N';
    else answer += 'A';

    return answer;
}