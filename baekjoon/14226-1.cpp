#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// variables
int S;
const int inf = 1000000000;

int main()
{
    // input
    cin >> S;
    
    // algorithm
    // 0이되면 더 이상 진행 불가!
    // 2X(2가중치), X-1(1가중치)로 나눌 수 없다. 복사, 붙여넣기, 붙여넣기, 붙여넣기....의 경우가 있다.
    // 정점의 상태 변화
    // (s, s)
    // (s+c, c)
    // (s-1, c)
    queue<pair<int, int> > q;
    bool visit[1001][1001];
    vector<vector<int> > dist(1001, vector<int>(1001, inf));
    
    // 초기화
    q.push(make_pair(1, 0));
    visit[1][0] = true;
    dist[1][0] = 0;
    
    // dijkstra를 써야하는가 bfs를 이용해야 하는가?
    // 가중치가 전부 1이므로 bfs 사용
    while(!q.empty()) {
        int s = q.front().first;
        int c = q.front().second;
        q.pop();
        
        // 복사
        int ns = s;
        int nc = s;
        if( (0 < ns && ns <= 1000) && !visit[ns][nc]) {
            q.push(make_pair(ns,nc));
            visit[ns][nc] = true;
            dist[ns][nc] = dist[s][c] + 1;            
        }
        
        // 붙여넣기
        ns = s+c;
        nc = c;
        if( (0 < ns && ns <= 1000) && !visit[ns][nc]) {
            q.push(make_pair(ns,nc));
            visit[ns][nc] = true;
            dist[ns][nc] = dist[s][c] + 1;            
        }
        
        // 삭제
        ns = s-1;
        nc = c;
        if( (0 < ns && ns <= 1000) && !visit[ns][nc]) {
            q.push(make_pair(ns,nc));
            visit[ns][nc] = true;
            dist[ns][nc] = dist[s][c] + 1;            
        }
    }
    
    int ret = inf;
    for(int i = 0; i < 1001; i++) {
        ret = min(ret, dist[S][i]);
    }
    cout << ret << endl;
    
    return 0;
}
