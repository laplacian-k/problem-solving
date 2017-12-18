#include <iostream>
using namespace std;

// variables
int N;
long long u[21];
long long c[21][21];

int main()
{
    int T;
    // input1
    cin >> T;
    
    // pre processing
    // nCr = n-1Cr-1 + n-1Cr
    c[0][0] = 1;
    c[0][1] = 0;
    c[1][0] = 1;
    
    for(int i = 1; i <= 20; i++) {
        for(int j = 0; j <= i; j++) {
            c[i][j] = c[i-1][j-1]+c[i-1][j];
        }
    }
    
    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j <= 20; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    
    while(T--) {
        // input2
        cin >> N;
        
        // algorithm
        // a[n] : n명의 병사를 배치하는 경우의 수
        // a[n] = u[n] + d[n]으로 나눌 수 있다. (u[n] : 첫번째 병사 < 두번째 병사, d[n] : 첫번째 병사 > 두번째 병사)
        // 4513의 u[n]을 생각했을 때 왼쪽으로 한칸을 밀어내면 5134의 d[n]이 된다. 따라서 u[n] = d[n], a[n] = 2*u[n]
        // 가장 큰 병사를 기준(j번째에 위치)으로 왼쪽과 오른쪽으로 나눌 수 있음
        // u[j-1]*u[i-j]*왼쪽에 위치할 병사를 고르는 경우의 수 = u[j-1]*u[i-j]*i-1Cj-1 (0<=j=<i j는 짝수)
        
        u[0] = u[1] = 1;
        
        for(int i = 2; i <= N; i++) {
            for(int j = 2; j <= i; j++) {
                // 홀수라면 skip
                if(j^1) continue;
                u[i] = u[j-1]*u[i-j]*c[i-1][j-1];
            }
        }
        long long ret = 0;
        ret = 2;
        ret = ret*u[N];        
        cout << ret << endl;
    }
    
    return 0;
}
