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
    queue<int> q;
    bool visit[2001];
    vector<int> dist(2001, inf);
    
    // 첫 이모티콘 개수
    q.push(1);
     visit[1] = true;
    dist[1] = 0;
    
    // dijkstra를 써야하는가 bfs를 이용해야 하는가?
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        int next = cur-1;
        if(next > 0 && !visit[next]) {
            if(dist[next] > dist[cur] + 1) {
                q.push(next);
                dist[next] = dist[cur] + 1;               
            }

        }
        
        next = cur*2;
        if(next > 0 && !visit[next]) {
            if(dist[next] > dist[cur] + 2) {
                q.push(next);
                dist[next] = dist[cur] + 2;
            }
        }        
    }
    
    cout << dist[S] << endl;
    
    return 0;
}
