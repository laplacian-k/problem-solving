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
                
        for(int x = 0; x < N; x++) {
            
            // 블럭을 위로 땡김
            vector<int> b1(N, 0);
            int idx = 0;
            for(int y = 0; y < N; y++) {
                if(board[y][x] != 0) {
                    b1[idx] = board[y][x];
                    idx++;
                }
            }
            
            // 인접한 블럭의 수가 같다면 합침
            // 한번 합쳐진 블럭은 다시 합칠 수 없음.
            vector<int> b2(N, 0);
            vector<bool> v(N, false);
            idx = 0;
            for(int i = 0; i < N; i++) {
                // 합쳐진 블럭이라면 비교 대상 x
                if(v[i]) continue;
                // 끝에 왔다면 무조건 집어 넣음.
                if(i == N-1) {
                    b2[idx] = b1[i];
                    continue;
                }
                // 수가 같다면 블럭을 합침
                if(b1[i] == b1[i+1]) {
                    b2[idx] = 2*b1[i];
                    idx++;
                    v[i] = v[i+1] = true;
                }
                // 수가 다르면 그대로
                else {
                    b2[idx] = b1[i];
                    idx++;
                }
            }
            // 보드판 갱신
            for(int y = 0; y < N; y++) {
                board[y][x] = b2[y];
            }
        }        
    }    
    // 하
    else if(dir == 1) {       

        for(int x = 0; x < N; x++) {

            // 블럭을 아래로 땡김
            vector<int> b1(N, 0);
            int idx = 0;
            for(int y = N-1; y >= 0; y--) {
                if(board[y][x] != 0) {
                    b1[idx] = board[y][x];
                    idx++;
                }
            }

            // 인접한 블럭의 수가 같다면 합침
            // 한번 합쳐진 블럭은 다시 합칠 수 없음.
            vector<int> b2(N, 0);
            vector<bool> v(N, false);
            idx = 0;
            for(int i = 0; i < N; i++) {
                // 합쳐진 블럭이라면 비교 대상 x
                if(v[i]) continue;
                // 끝에 왔다면 무조건 집어 넣음.
                if(i == N-1) {
                    b2[idx] = b1[i];
                    continue;
                }
                // 수가 같다면 블럭을 합침
                if(b1[i] == b1[i+1]) {
                    b2[idx] = 2*b1[i];
                    idx++;
                    v[i] = v[i+1] = true;
                }
                // 수가 다르면 그대로
                else {
                    b2[idx] = b1[i];
                    idx++;
                }
            }
            // 보드판 갱신
            for(int y = 0; y < N; y++) {
                board[y][x] = b2[N-1-y];
            }
        }        
    }
    // 좌
    else if(dir == 2) {       
                
        for(int y = 0; y < N; y++) {
            
            // 블럭을 왼쪽으로 땡김
            vector<int> b1(N, 0);
            int idx = 0;
            for(int x = 0; x < N; x++) {
                if(board[y][x] != 0) {
                    b1[idx] = board[y][x];
                    idx++;
                }
            }
            
            // 인접한 블럭의 수가 같다면 합침
            // 한번 합쳐진 블럭은 다시 합칠 수 없음.
            vector<int> b2(N, 0);
            vector<bool> v(N, false);
            idx = 0;
            for(int i = 0; i < N; i++) {
                // 합쳐진 블럭이라면 비교 대상 x
                if(v[i]) continue;
                // 끝에 왔다면 무조건 집어 넣음.
                if(i == N-1) {
                    b2[idx] = b1[i];
                    continue;
                }
                // 수가 같다면 블럭을 합침
                if(b1[i] == b1[i+1]) {
                    b2[idx] = 2*b1[i];
                    idx++;
                    v[i] = v[i+1] = true;
                }
                // 수가 다르면 그대로
                else {
                    b2[idx] = b1[i];
                    idx++;
                }
            }
            // 보드판 갱신
            for(int x = 0; x < N; x++) {
                board[y][x] = b2[x];
            }
        }        
    }
    // 우
    else if(dir == 3) {       

        for(int y = 0; y < N; y++) {

            // 블럭을 오른쪽으로 땡김
            vector<int> b1(N, 0);
            int idx = 0;
            for(int x = N-1; x >= 0; x--) {
                if(board[y][x] != 0) {
                    b1[idx] = board[y][x];
                    idx++;
                }
            }

            // 인접한 블럭의 수가 같다면 합침
            // 한번 합쳐진 블럭은 다시 합칠 수 없음.
            vector<int> b2(N, 0);
            vector<bool> v(N, false);
            idx = 0;
            for(int i = 0; i < N; i++) {
                // 합쳐진 블럭이라면 비교 대상 x
                if(v[i]) continue;
                // 끝에 왔다면 무조건 집어 넣음.
                if(i == N-1) {
                    b2[idx] = b1[i];
                    continue;
                }
                // 수가 같다면 블럭을 합침
                if(b1[i] == b1[i+1]) {
                    b2[idx] = 2*b1[i];
                    idx++;
                    v[i] = v[i+1] = true;
                }
                // 수가 다르면 그대로
                else {
                    b2[idx] = b1[i];
                    idx++;
                }
            }
            // 보드판 갱신
            for(int x = 0; x < N; x++) {
                board[y][x] = b2[N-1-x];
            }
        }        
    }
    
    return board;
}

int game(int d, vector<vector<int> >& board)
{
    // 다섯번 움직였을 때 답을 구한다.
    if(d == 5) {
        int ret = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                ret = max(ret, board[i][j]);
            }
        }
        return ret;
    }
    
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
