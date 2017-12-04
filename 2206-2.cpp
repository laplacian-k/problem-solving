#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

// variables
int N, M;
int m[1000][1000];
bool visit[1000][1000];
int dist[1000][1000][2];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int inf = 100000000;

int main()
{
    // input
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s = "";
        cin >> s;
        for(int j = 0; j < M; j++) {
            if(s[j] == '0') m[i][j] = 0;
            else if(s[j] == '1') m[i][j] = 1;
        }
    }
    
    // init
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visit[i][j] = false;
            for(int k = 0; k < 2; k++) {
                dist[i][j][k] = inf;
            }
        }
    }
    
    // output
    /*
    cout << N << " " << M << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }   
    */
    
    // algorithm
    // 한 번 방문한 곳은 재방문하지 않음. (visit 필요)
 
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(0, 0, 1));    // 벽을 부술 수 있음
    dist[0][0][1] = 1;
    
    while(!q.empty()) {
        // 방문
        int y, x, d;
        tie(y, x, d) = q.front();
        q.pop();
        visit[y][x] = true;
        
        for(int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            
            // 범위를 벗어난다면 skip
            if( !((0 <= ny && ny < N) && (0 <= nx && nx < M))) continue;
            
            // 아직 방문한적 없다면(dist가 존재한다는 것은 이미 방문했다는 것)
            // 빈칸일 경우
            if(m[ny][nx] == 0 && dist[ny][nx][d] == inf) {
                dist[ny][nx][d] = dist[y][x][d] + 1;
                q.push(make_tuple(ny, nx, d));
            }
            // 벽이고 벽을 부술 수 있는 경우
            else if(m[ny][nx] == 1 && d == 1 && dist[ny][nx][0] == inf) {
                dist[ny][nx][0] = dist[y][x][1] + 1;
                q.push(make_tuple(ny, nx, 0));    // 벽을 더이상 부술 수 없음.
            }
        }
        
    }
    
    int ret1 = dist[N-1][M-1][0];
    int ret2 = dist[N-1][M-1][1];
    
    if(ret1 == inf && ret2 == inf) {
        cout << -1 << endl;    // 정답 없음
    }
    else {
        cout << min(ret1, ret2) << endl;
    }  
    
    return 0;    
}
