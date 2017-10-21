#include <iostream>
#include <queue>
#include <string>
using namespace std;

// variables
int N, M;
int miro[101][101];
bool visit[101][101];
const int dy[] = {-1, 1, 0, 0};    // 상하좌우
const int dx[] = {0, 0, -1, 1};
int dist[101][101];

//int ans;
void bfs(int a, int b)
{
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    dist[1][1] = 1;    
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == N && x == M) break;
        if(visit[y][x]) continue;
        visit[y][x] = true;
        
        bool canGo = false;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            //if(visit[ny][nx]) continue;
            if(!((1 <= ny && ny <= N) && (1 <= nx && nx <= M))) continue;
            if(miro[ny][nx] == 0) continue;
            
            q.push(make_pair(ny, nx));
            dist[ny][nx] = 1 + dist[y][x];
        }
    }
}
// functions
int main()
{
    // init
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            visit[i][j] = false;
        }
    }
    //ans = 0;
    
    // input
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        string m;
        cin >> m;
        for(int j = 1; j <= M; j++) {
            miro[i][j] = m[j-1] - '1' + 1;
        }
    }
    
    // algorithm
    bfs(1, 1);
    //cout << ans << endl;
    cout << dist[N][M] << endl;
    
    return 0;
}
