#include <iostream>
#include <string>
#include <queue>
using namespace std;

// variables
int N, M;
int r[100][100];
bool visit[100][100];
int dist[100][100];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int inf = 100000000;

// functions

int main()
{
    // init
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            visit[i][j] = false;
            dist[i][j] = inf;
        }
    }
    // input
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        string s = "";
        cin >> s;
        for(int j = 0; j < M; j++) {
            if(s[j] == '0') r[i][j] = 0;
            else if(s[j] == '1') r[i][j] = 1;
        }
    }
    
    // output
    /*
    cout << N << " " << M << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    } 
    */
    
    // algorithm
    // (0, 0)에서부터 (N, M)까지 도달하기 위해 깨야하는 벽돌의 최소 개수를 구함 
    int ret = 0;

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    dist[0][0] = 0;
    while(!q.empty()) {        
        int y = q.front().first;
        int x = q.front().second;
        //cout << y << ", " << x << endl;
        // 방문!
        q.pop();
        visit[y][x] = true;
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 범위를 벗어나면 skip
            if(!((0 <= ny && ny < N) && (0 <= nx && nx < M))) continue;
            // 이미 방문했다면 skip
            //if(visit[ny][nx]) continue;
            // 최소가 갱신된다면
            //cout << "dist[next] : " << dist[ny][nx] << endl;
            //cout << "dist[cur] : " << dist[y][x] << endl;
            //cout << "w : " << r[ny][nx]<< endl;
            if(dist[ny][nx] > dist[y][x] + r[ny][nx]) {
                dist[ny][nx] = dist[y][x] + r[ny][nx];
                q.push(make_pair(ny, nx));
            }
        }        
        
    }
    
    ret = dist[N-1][M-1];
    cout << ret << endl;
    return 0;
}
