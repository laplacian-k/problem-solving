#include<iostream>
using namespace std;

// variables
int N, S;
int a[20];
int ans;

// functions
void go(int d, int sum)
{
    if(d == N) {
        // S와 합이 같다면 정답 1 증가
        if(sum == S) ans += 1;
        return;
    }
    // a[d] 포함
    go(d+1, sum+a[d]);
    // a[d] 불포함
    go(d+1, sum);
    
    return;
}

int main()
{
    // input
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    /*
    cout << N << ", " << S << '\n';
    for(int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    */
    
    // algorithm
    // 2^N DFS 수행. depth가 끝났을 때 판단
    ans = 0;
    go(0, 0);
    // 공집합의 경우의 수를 제거
    if(S == 0) cout << ans-1 << '\n';
    else cout << ans << '\n';
    return 0;
}
