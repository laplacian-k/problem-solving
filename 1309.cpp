#include <iostream>
using namespace std;

// variables
int N;
const int MOD = 9901;
int d[100001][3];
int main()
{
    // input
    cin >> N;
    
    // algorithm
    // a[n] = 2*n 크기 우리에 사자를 배치하는 경우의 수
    // a[n] = d[n][0] + d[n][1] + d[n][2]
    // d[n][k] = 2*n 크기 우리에 사자를 k방향에 두는 경우의 수(k : 없음(0) 왼(1) 오(2) )
    // d[n+1][0] = d[n][0] + d[n][1] + d[n][2]
    // d[n+1][1] = d[n][0] + d[n][2]
    // d[n+1][2] = d[n][0] + d[n][1]
    d[1][0] = d[1][1] = d[1][2] = 1;
    for(int i = 2; i <= N; i++) {
        d[i][0] = ((d[i-1][0] + d[i-1][1])%MOD + d[i-1][2])%MOD;
        d[i][1] = (d[i-1][0] + d[i-1][2])%MOD;
        d[i][2] = (d[i-1][0] + d[i-1][1])%MOD;
    }
    
    cout << ((d[N][0] + d[N][1])%MOD + d[N][2])%MOD << endl;
    
}
