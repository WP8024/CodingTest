#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    deque<deque<int>> templist;
    deque<int> temp;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[j][i]!=0){
                temp.push_back(board[j][i]);
            }
        }
        templist.push_back(temp);
        temp.clear();
    }
    int cur=0;
    for(auto move:moves){
        int i = move - 1;
        if(!templist[i].empty()){
            if(cur==templist[i].front()){
                answer++;
            }
            cur=templist[i].front();
            templist[i].pop_front();
        }        
    }
    return answer;
}

int main() {
    vector<vector<int>> board = { { 0,0,0,0,0 },{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    solution(board, { 1,5,3,5,1,2,1,4 });

    return 0;
}