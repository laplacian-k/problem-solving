#include <iostream>
#include <vector>
#include <string>
#include <cassert>    // for assert
using namespace std;
 
// variables
int N, M;
int ans;
const int inf = 1000000000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
bool bh;
bool rh;
 
// functions
vector<string> update(vector<string> cur, int ndir)
{    
    // 빨간, 파란 구슬이 구멍에 빠질 경우 bh, rh로 컨트롤
 
    // 빨간구슬과 파란구슬, 구멍의 위치를 찾는다.
    int ry = -1;
    int rx = -1;
    int by = -1;
    int bx = -1;
    int hy = -1;
    int hx = -1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(cur[i][j] == 'O') {
                hy = i;
                hx = j;
            }
            if(cur[i][j] == 'R') {
                ry = i;
                rx = j;
            }
            if(cur[i][j] == 'B') {
                by = i;
                bx = j;
            }
        }
    }
    vector<string> next = cur;
 
    // ndir방향으로 구슬을 움직임
    // 상하좌우 방향에 따라 같은 축에 존재할 경우엔 순서를 고려한다.
    // 나머지 경우는 장애물을 먼저 만나는지 구멍을 먼저 만나는지만 고려하면 된다.
 
    // 먼저 움직일 구슬을 정함.
    int prior = 0;    // equal(0), red(1), blue(2)    
    // 상하
    if((ndir == 0 || ndir ==1) && (rx == bx)) {
        // 같을 수 없음. false 리턴일 경우 프로그램 종료
        assert(ry != by);
        if(ry < by) prior = (ndir == 0)? 1 : 2;
        else prior = (ndir == 0)? 2 : 1;
    }
 
    // 좌우
    if((ndir == 2 || ndir ==3) && (ry == by)) {
        // 같을 수 없음
        assert(rx != bx);
        if(rx < bx) prior = (ndir == 2)? 1 : 2;
        else prior = (ndir == 2)? 2 : 1;
    }
    //cout << "ndir = " << ndir << '\n';
    //cout << prior << '\n';
 
    // 둘다 갈 수 없을 때 종료
    bool rGo = true;
    bool bGo = true;
    
    while(rGo || bGo) {
        //cout << ry << ", " << rx << "/" << by << ", " << bx << '\n';
        //cout << rGo << ", " << bGo << '\n';
        int nry = ry + dy[ndir];
        int nrx = rx + dx[ndir];
 
        int nby = by + dy[ndir];
        int nbx = bx + dx[ndir];       
 
        // red를 먼저 움직여야 함
        if(prior <= 1) {
            // 장애물이나 구멍이라면 더 이상 갈 수 없음.
            if(next[nry][nrx] == '#' || next[nry][nrx] == 'O') {
                rGo = false;
                // 구멍일 경우 구슬 삭제
                if(next[nry][nrx] == 'O') {
                    next[ry][rx] = '.';                    
                    // 빠짐 체킹
                    rh = true;
                }
            }
            else {
                // 구슬 이동
                swap(next[nry][nrx], next[ry][rx]);
                ry = nry;
                rx = nrx;                    
            }    
 
            // 장애물이거나 빨간 구슬이거나 구멍일 경우
            if(next[nby][nbx] == '#' || next[nby][nbx] == 'R' || next[nby][nbx] == 'O') {
                bGo = false;
                // 구멍일 경우 구슬 삭제
                if(next[nby][nbx] == 'O') {
                    next[by][bx] = '.';                    
                    // 빠짐 체킹
                    bh = true;
                }
            }
            else {
                // 구슬 이동
                swap(next[nby][nbx], next[by][bx]);
                by = nby;
                bx = nbx;
            }
        }        
        // blue를 먼저 움직여야 함
        else if(prior == 2) {
            if(next[nby][nbx] == '#' || next[nby][nbx] == 'O') {
                bGo = false;
                // 구멍일 경우 구슬 삭제
                if(next[nby][nbx] == 'O') {
                    next[by][bx] = '.';                    
                    // 빠짐 체킹
                    bh = true;
                }
            }
            else {
                // 구슬 이동
                swap(next[nby][nbx], next[by][bx]);
                by = nby;
                bx = nbx;
            }
 
            if(next[nry][nrx] == '#' || next[nry][nrx] == 'B' || next[nry][nrx] == 'O') {
                rGo = false;
                // 구멍일 경우 구슬 삭제
                if(next[nry][nrx] == 'O') {
                    next[ry][rx] = '.';                    
                    // 빠짐 체킹
                    rh = true;
                }
            }
            else {
                // 구슬 이동
                swap(next[nry][nrx], next[ry][rx]);
                ry = nry;
                rx = nrx;
            }                
        }
    }
 
    return next;    
}
 
void go(vector<string>& cur, int dir, int d, bool b, bool r)
{
    //cout << "d = " << d << ", dir = " << dir << '\n';
    //for(int i = 0; i < N; i++) {
    //    cout << cur[i] << '\n';
    //}
    
    // 가지치기. 현재 정답보다 d가 크다면 가지 않는다.
    if(ans <= d) return;
    // 10번을 초과하여 이동했다면 return
    if(d > 10) return;
    // 파란공이 구멍에 들어갔다면
    if(b) return;
    // 빨간공이 구멍에 들어갔다면
    if(r) {
        ans = min(ans, d);
        return;
    }
 
    // board update
    for(int ndir = 0; ndir < 4; ndir++) { 
        // 같은 방향으로는 가지 않음.
        if(ndir == dir) continue;
        // 상->하, 하->상, 좌->우, 우->좌 도 무의미한 이동.(구슬이 중간에 위치하는 경우는 처음밖에 없다)
        if(dir == 0 && ndir == 1) continue;
        if(dir == 1 && ndir == 0) continue;
        if(dir == 2 && ndir == 3) continue;
        if(dir == 3 && ndir == 2) continue;
        
        //cout << "dir = " << dir << ", " << "ndir = " << ndir << '\n';
 
        // board update
        // 파란구슬, 빨간구슬이 구멍에 빠졌는지도 알아야 함.
        rh = bh = false;
        vector<string> next = update(cur, ndir);
        go(next, ndir, d+1, bh, rh);     
    }
 
    return;
}
int main()
{
    // init
    ans = inf;
    bh = rh = false;
 
    // input
    cin >> N >> M;
    vector<string> board(N);
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
    go(board, -1, 0, bh, rh);
 
    if(ans == inf) cout << -1 << '\n';    
    else cout << ans << '\n';
 
    return 0;
}
