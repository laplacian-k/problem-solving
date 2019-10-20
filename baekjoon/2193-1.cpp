#include <iostream>
using namespace std;

// variables
int N;
long long d[91][2];

int main()
{
    // input
    cin >> N;
    
    // algorithm
    // 이친수는 0으로 시작하지 않음. 연속되는 1이 나오지 않음
    // d[n][m] = 끝자리가 m으로 끝나는 n자리 이친수를 만드는 경우의 수
    // d[n][0] = d[n-1][0] + d[n-1][1]
    // d[n][1] = d[n-1][0]
    d[1][0] = 0;
    d[1][1] = 1;
    
    for(int i = 2; i <= N; i++) {
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }
    
    long long ret = d[N][0] + d[N][1];
    cout << ret << endl;
    
    return 0;
}
