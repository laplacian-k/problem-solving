#include <iostream>
#include <vector>
#include <string>
using namespace std;

// variables
int N, M;
int ans;
const int inf = 1000000000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

// functions
vector<vector<int> > update(vector<vector<int> > cur, int dir)
{
    vector<vector<int> > next = cur;
    // 장애물을 만날때까지 한칸씩 이동
    // 빨간구슬과 파란구슬을 한칸씩 이동(동시에) -> while문으로 둘 다 이동할 수 없을 때까지 이동해야함.
    // 두 구슬은 한 칸에 겹칠 수 없음
    // 상
    if(dir == 0) {
        
    }
    // 하
    else if(dir == 1) {
        
    }
    // 좌
    else if(dir == 2) {
        
    }
    // 우
    else if(dir == 3) {
        
    }
    
    

    
    
    return next;
}
void go(vector<vector<int> >& cur, int dir, int d, bool blue, bool red)
{
    // 가지치기. 현재 정답보다 d가 크다면 가지 않는다.
    if(ans <= d) return;
    // 10번을 초과하여 이동했다면 return
    if(d > 10) return;
    // 파란공이 구멍에 들어갔다면
    if(blue) return;
    // 빨간공이 구멍에 들어갔다면
    if(red) {
        ans = min(ans, d);
        return;
    }
    
    for(int ndir = 0; ndir < 4; ndir++) {
        // 같은 방향으로는 가지 않음.
        if(ndir == dir) continue;
        vector<vector<int> > next = cur;
        
        // update board
        // update(next, ndir);
        
        // 빨간구슬, 파란구슬의 위치를 찾음
        int ry = -1;
        int rx = -1;
        int by = -1;
        int bx = -1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(cur[i][j] == 'R') {
                    ry = i;
                    rx = j;
                }
                if(cur[i][j] == 'B') {
                    by = i;
                    by = j;
                }
            }
        }        
        
        // 먼저 움직일 구슬을 찾는다.
        int prior = 0;    // equal(0), red(1), blue(2)        
        if(rx == bx) {
            // 상
            if(ndir == 0) {
                if(ry > by) prior = 1;
                else if(ry < by) prior = 2;
            }            
            // 하
            else if(ndir == 1) {
                if(ry > by) prior = 2;
                else if(ry < by) prior = 1;                
            }
        }
        
        if(ry == rx) {
            // 좌
            if(ndir == 2) {
                if(rx > bx) prior = 2;
                else if(rx < bx) prior = 1;                
            }
            // 우
            else if(ndir == 3) {
                if(rx > bx) prior = 1;
                else if(rx < bx) prior = 2;                
            }
        }
        
        // 둘다 갈 수 없을 때 종료
        bool redGo = true;
        bool blueGo = true;
        while(1) {
            if(!redGo && !blueGo)
            // 상하좌우에 따라 먼저 움직일 구슬을 선택해야함.
            int nry = ry + dy[dir];
            int nrx = rx + dx[dir];
            // 장애물이거나 blue면 갈 수 없음.
            
            int nby = by + dy[dir];
            int nbx = bx + dx[dir];
            // 장애물이거나 red면 갈 수 없음.
            
            ry = nry;
            rx = nrx;
            
            by = nby;
            bx = nbx;
        
        }                
            }
            else {
                
            }
        }
        // 빨간구슬, 파란구슬 모두 갈 곳이 없을 때까지
        bool b = false;
        bool r = false;
    

    
    if(dir != -1) {

    }
        if(ndir == 0) {
            
        }
        
        
        go(next, ndir, d+1, b, r);
    }
    
    return;
}
int main()
{
    // init
    ans = inf;
    
    // input
    cin >> N >> M;
    vector<string> board(M);
    for(int i = 0; i < N; i++) {
        cin >> board[i];
    }
    /*
    cout << N << ", " << M << '\n';
    for(int i = 0; i < N; i++) {
        cout << board[i] << '\n';
    }
    */
    // algorithm
    // 가장 바깥의 행과 열은 모두 막혀 있다.
    // 빨간구슬을 구멍을 통해 빼내야함. (파란구슬이 빠지면 안됨.)
    // 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다.
    // 보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.
    
    // 상하좌우로 이동
    go(board, -1, 0, false, false);
    
    if(ans == inf) cout << -1 << '\n';    
    else cout << ans << '\n';
    
    return 0;
}
