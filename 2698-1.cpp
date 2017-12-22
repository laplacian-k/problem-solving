#include <iostream>
using namespace std;

// variables
int N, K;
int d[101][101][2];

//functions

int main()
{
    int T;
    cin >> T;
    
    // algorithm
    // 인접한 비트의 개수가 k인 수열 S의 개수를 출력
    // a[n][k] : n자리 비트 중 인접비트가 k개인 수열 S의 개수
    // a[n][k] = d[n][k][1] + d[n][k][0] (끝자리가 1, 끝자리가 0)
    // d[n][k][1] = d[n-1][k-1][1] + d[n-1][k][0]
    // d[n][k][0] = d[n-1][k][1] + d[n-1][k][0]

    d[1][0][0] = d[1][0][1] = 1;

    for(int n = 2; n <= 100; n++) {
        for(int k = 0; k < n; k++) {
            d[n][k][1] = d[n-1][k][0];
            d[n][k][0] = d[n-1][k][1] + d[n-1][k][0];
            if(k-1 >= 0) {
                d[n][k][1] += d[n-1][k-1][1];
            }
        }
    }
    
    while(T--) {
        // input
        cin >> N >> K;
        
        // output
        //cout << N << " " << K << endl;
        

        cout << d[N][K][1] + d[N][K][0] << endl;
    }
    
    return 0;
}
