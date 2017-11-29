#include <iostream>
#include <queue>
using namespace std;

// variables
int N, K;
const int inf = 100000;
bool visit[100000];
int dist[100000];

int main()
{
    // input
    cin >> N >> K;
    
    // init
    //visit[N] = true;
    //dist[N] = inf;
    
    /*
    cout << N << " " << K << endl;
    for(int i = 0; i < N; i++) {
        cout << "visit : " << visit[i] << endl;
    }
    
    for(int i = 0; i < N; i++) {
        cout << "dist : " << dist[i] << endl;
    }
    */
    
    // algorithm    
    queue<int> q;
    queue<int> nq;
    q.push(N);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int next = cur*2;
        if(next < inf && !visit[next]) {
            q.push(next);
            visit[next] = true;
            dist[next] = dist[cur];
        }
        
        next = cur-1;
        if(next >= 0 && !visit[next]) {
            q.push(next);
            visit[next] = true;
            dist[next] = dist[cur] + 1;
        }
        
        next = cur+1;
        
        if(next < inf && !visit[next]) {
            q.push(next);
            visit[next] = true;
            dist[next] = dist[cur] + 1;
        }
        
        // 순간이동에 대한 큐가 비었을 경우 일반이동에 대한 큐데이터를 전부 순간이동 쪽으로 옮긴ㄷㅏ.
        if(q.empty()) {
            q = nq;
            nq = queue<int>();
        }
    }
    
    int ret = dist[K];
    
    
    cout << ret << endl;
    
    return 0;
}
