#include <iostream>
using namespace std;

// variables
int N;
int MOD = 1000000000;
int d[101][10];

int main()
{
    // input
    cin >> N;
    
    // algorithm
    // d[n][m] = 끝자리가 m으로 끝나는 n자리 계단수를 만드는 경우의 수
    // d[n][0] = d[n-1][1]
    // d[n][9] = d[n-1][8]
    // d[n][m] = d[n-1][m-1] + d[n-1][(m+1)%10] (1 <= m <= 8)
    
    d[1][0] = 0;
    // init
    for(int i = 1; i <= 9; i++) {
        d[1][i] = 1;
    }
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == 0) {
                d[i][j] = d[i-1][j+1]%MOD;
            }
            else if(j == 9) {
                d[i][j] = d[i-1][j-1]%MOD;
            }
            else {
                d[i][j] = (d[i-1][j-1]%MOD + d[i-1][j+1]%MOD)%MOD;
            }
        }
    }
    
    int ret = 0;
    for(int i = 0; i <= 9; i++) {
        ret = (ret%MOD + d[N][i]%MOD)%MOD;
    }
    cout << ret << endl;
    
    return 0;
}
