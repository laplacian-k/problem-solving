#include <iostream>
#include <algorithm>
using namespace std;

// variables
int N;
int s[50001];
int a[50001];
int d[50001][4];
int K;

// functions
int sum(int x, int y)
{
    return s[y]-s[x-1];
}
int main()
{
    // input
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >>a[i];
        // pre processing
        s[i] = s[i-1] + a[i];
    }
    cin >> K;
    
    // algorithm
    // d[i][j] = i개의 객차를 j개의 소형기관차로 나눴을 경우 운송할 수 있는 최대 승객의 수
    // i번째 객차를 운송했을 경우, 운송하지 않을 경우로 나눠볼 수 있음
    // 운송하지 않을 경우 d[i-1][j]
    // 운송할 경우 d[i-K][j-1] + A[i-m+1]~A[i]의 합
    // d[i][j] = max(d[i-1][j], d[i-K][j-1] + sum(i-m+1, i))
    for(int j = 1; j <= 3; j++) {
        for(int i = j*K; i <= N; i++) {
            d[i][j] = max(d[i-1][j], d[i-K][j-1] + sum(i-K+1, i));
        }
    }
    
    cout << d[N][3] << endl;
     
}
