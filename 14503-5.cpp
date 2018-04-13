#include <iostream>
using namespace std;

// variables
int N, M;
int a[51][51];
// 북동남서
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int dir[] = {0, 1, 2, 3};

int main()
{
    // input
    cin >> N >> M;
    int y, x, d;
    cin >> y >> x >> d;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    // algorithm
    int ret = 0;
    while(1) {
        // 현재 위치를 청소
        if(a[y][x] == 0) {
            a[y][x] = 2;    // 0 빈칸, 1 벽, 2 청소
            ret += 1;
        }
        
        bool canGo = false;
        // 왼쪽을 탐색(d에 따라)
        for(int i = 0; i < 4; i++) {
          
            // d : 북동남서(0123)
            // nd: 서북동남(3012)
            int nd = dir[(d-1+4)%4];
            int ny = y + dy[nd];
            int nx = x + dx[nd];
            
            // 범위를 벗어나면 skip
            if(!((0 <= y && y < N) && (0 <= x && x < M))) continue;
            
            // 청소가 가능하다면 그 방향으로 회전하고 한칸 전진
            if(a[ny][nx] == 0){
                d = nd;
                y = ny;
                x = nx;
                canGo = true;
                break;
            }
            // 불가능하다면 회전만 진행
            else {
                d = nd;
            }  
            
        }
        
        // 네 방향 모두 벽이거나 이미 청소를 한 경우
        if(!canGo) {
            // 왼쪽으로 두번 방향을 바꾸면 후진
            int nd1 = dir[(d-1+4)%4];
            int nd2 = dir[(nd1-1+4)%4];
            
            int by = y + dy[nd2];
            int bx = x + dx[nd2];
            
            // 후진을 할 수 없으면(벽이 있으면) 종료
            if(a[by][bx] == 1) break;
            else {
                // 후진
                y = by;
                x = bx;
            }
        }
    }
    
    cout << ret << "\n";
    return 0;
}
