#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class ABoardGame {
public:
	string whoWins(vector<string> board);
       
};

string ABoardGame::whoWins(vector<string> board) {
    int L = board.size();
    int N = L/2;
	vector<int> regions(N+1, 0);
    vector<pair<int, int> > bases;
    
    // make bases
    for(int i = N-1; i <= N; i++) {
        for(int j = N-1; j <= N; j++) {
            bases.push_back(make_pair(i, j));
        }
    }
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].length(); j++) {
            int y = bases[0].first;
            int x = bases[0].second;
            
            int dir = -1;
            if(i <= y && j <= x) dir = 0;
            else if(i <= y && j > x) dir = 1;
            else if(i > y && j <= x) dir = 2;
            else if(i > y && j > x) dir = 3;
            
            int ny = bases[dir].first;
            int nx = bases[dir].second;
            
            int index = max(abs(i-ny), abs(j-nx)) + 1;
            if(board[i][j] == 'A') {regions[index]++;}
            else if(board[i][j] == 'B') {regions[index]--;}
        }
    }
                
    
    int ret = 0;
    for(int i = 1; i < regions.size(); i++) {
        if(regions[i] > 0) {ret = 1; break;}
        else if(regions[i] < 0) {ret = -1; break;}
    }
               
    if(ret > 0) return "Alice";
    else if(ret < 0) return "Bob";
    else return "Draw";
}
