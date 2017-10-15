#include <iostream>
#include <vector>
using namespace std;

// variables
int N;

// functions

// 보드판 갱신
vector<vector<int> > update(int dir, vector<vector<int> > board)
{
    // 상
    if(dir == 0) {
        // 블럭을 위로 땡김
        
        // 인접한 블럭의 수가 같다면 합침
        // 한번 합쳐진 블럭은 다시 합칠 수 없음.
    }

    
    // 하
    // 좌
    // 우
    return board;
}

int game(int d, vector<vector<int> >& board)
{
    // 다섯번 움직였을 때 답을 구한다.
    if(d > 5) return 0;
    
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        vector<vector<int> > b = update(i, board);
        ret = max(ret, game(d+1, b));
    }
    
    return ret;
}
int main()
{
    // input
    cin >> N;
    vector<vector<int> > board(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    // algorithm
    int ret = 0;
    ret = game(0, board);
    cout << ret << endl;
}
