#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// variables
int N, K;
const int MAX = 200000;
bool visit[MAX+1];
int dist[MAX+1];
int from[MAX+1];


int main()
{
    // init
    for(int i = 0; i <= MAX; i++) {
        visit[i] = false;
    }
    
    // input
    cin >> N >> K;
    
    // algorithm
    // 1초 후에 갈 수 있는 거리. X-1, X+1, 2*X -> 상태의 정의
    // 왜 dp로는 풀 수 없을까?
    
    // 시작점 정의
    queue<int> q;
    q.push(N);
    visit[N] = true;
    dist[N] = 0;
    from[N] = -1;
    
    while(!q.empty()) {
        int X = q.front();
        q.pop();
        
        // 동생을 찾았으면 탈출
        // 방문할 정점이 없을 때까지 전부 다 해본다음에 dist[K] 를 정답으로 출력하면 된다.
        //if(X == K) break;
        
        // X-1        
        if(0 <= X-1 && X-1 <= MAX && !visit[X-1]) {
            visit[X-1] = true;
            q.push(X-1);
            dist[X-1] = dist[X] + 1;
            from[X-1] = X;
        }
        // X+1
        if(0 <= X+1 && X+1 <= MAX && !visit[X+1]) {
            visit[X+1] = true;
            q.push(X+1);
            dist[X+1] = dist[X] + 1;
            from[X+1] = X;
        }        
        // 2*X
        if(0 <= 2*X && 2*X <= MAX && !visit[2*X]) {
            visit[2*X] = true;
            q.push(2*X);
            dist[2*X] = dist[X] + 1;
            from[2*X] = X;
        }
    }
    
    cout << dist[K] << endl;
    
    int cur = K;
    stack<int> path;
    while(cur != -1) {
        path.push(cur);
        cur = from[cur];
    }
    
    while(!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
    
    return 0;
}
