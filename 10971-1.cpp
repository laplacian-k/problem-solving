#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

// variables
int N;
int w[11][11];
int start;
int visit;
const int inf = 1000000000;
int ans;

// functions
void go(int cur, int val)
{   
    cout << bitset<32>(visit) << '\n';
    cout << bitset<32>((1<<N)-1) << '\n';
    cout << cur << ", " << val << '\n';
    // 전부 다 방문했고 마지막 도시에서 start로 갈 수 있을 경우 끝남
    if(visit == ((1<<N)-1) && w[cur][start] != 0) {
        cout << "전부 방문" << '\n';
        ans = min(ans, val+w[cur][start]);
        return;
    }
    // 전부 방문하기만 했을 경우 종료시킴
    if(visit == ((1<<N)-1)) {
        cout << "전부 방문" << '\n';
        return;
    }
    
    int ret = inf;
    for(int next = 1; next <= N; next++) {
        // 이동할 수 없다면 skip
        if(w[cur][next] == 0) continue;
        // 이미 방문했다면 skip
        if(visit&(1<<(next-1))) continue;
        
        // visit 기록
        visit |= (1<<(next-1));
        go(next, val+w[cur][next]);
        // visit 삭제
        visit &= ~(1<<(next-1));
    }
    
    return;
}

int main()
{
    // init
    visit = 0;
    ans = inf;
    
    // input
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> w[i][j];
        }
    } 
    
    // algorithm
    for(int i = 1; i <= N; i++) {
        start = i;
        // visit 기록
        visit |= (1<<(i-1));
        go(i, 0);
        // visit 삭제
        visit &= ~(1<<(i-1));
    }
    
    cout << ans << '\n';
    return 0;
}
