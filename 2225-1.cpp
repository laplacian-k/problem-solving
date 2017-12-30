#include <iostream>
using namespace std;

// variables
int N, K;
int d[201][201];
const int MOD = 1000000000;

int main()
{
    // input
    cin >> N >> K;
    
    // algorithm
    // d[i][j] = 0에서 i까지의 정수 j개를 더해서 i를 만드는 경우의 수.
    // 중복된 수 사용 가능.
    // 더하기 순서가 다르면 다른 경우의 수
    // d[i][j] = d[i-k][j-1] (0 <= k <= i)
    
    for(int i = 0; i <= 200; i++) {
        d[0][i] = 1;
        // d[i][0] = 0; -> 초기화 안해도 0이고 d[0][0]의 경우는 1이어야 함.
        // d[i][1] = 1; -> 아래 반복문에서 구해지고, 미리 초기화할 경우 부분정답보다 커지게 된다. (+= 연산 때문)
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            for(int k = 0; k <= i; k++) {
                d[i][j] = (d[i][j]%MOD + d[i-k][j-1]%MOD)%MOD;
            }
        }
    }
    
    cout << d[N][K] << endl;
    
    return 0;
}
