#include <iostream>
#include <string>
#include <queue>
using namespace std;

// variables
int N, M;
int m[1000][1000];
bool visit[1000][1000];
int dist[1000][1000];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

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
            dist[i][j] = -1;
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
 
    queue<pair<int, int> > q;
    queue<bool> d;
    q.push(make_pair(0, 0));
    d.push(true);
    dist[0][0] = 1;
    
    while(!q.empty()) {
        // 방문
        int y = q.front().first;
        int x = q.front().second;
        bool canDestroy = d.front();
        q.pop();
        d.pop();
        visit[y][x] = true;
        
        for(int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            
            // 범위를 벗어난다면 skip
            if( !((0 <= ny && ny < N) && (0 <= nx && nx < M))) continue;
            // 이미 방문했다면 skip
            //if(visit[ny][nx]) continue;
            
            // 아직 방문한적 없다면(dist가 존재한다는 것은 이미 방문했다는 것)
            if(dist[ny][nx] == -1) {
                // 빈칸일 경우
                if(m[ny][nx] == 0) {
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push(make_pair(ny, nx));
                    d.push(canDestroy);
                }
                // 벽이고 벽을 부술 수 있는 경우
                else if(m[ny][nx] == 1 && canDestroy) {
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push(make_pair(ny, nx));
                    d.push(false);    // 벽을 더이상 부술 수 없음.
                }
            }
        }
        
    }
    
    int ret = 0;
    ret = dist[N-1][M-1];
    cout << ret << endl;    
    
    return 0;    
}
