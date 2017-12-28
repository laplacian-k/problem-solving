#include <iostream>
using namespace std;

// variables
int n;
const int MOD = 10007;
int d[1001];

int main()
{
    // input
    cin >> n;
    
    // algorithm
    // d[n] : 2xn 타일을 1x2, 2x1, 2x2타일로 채우는 경우의 수
    // d[n] = d[n-1] + d[n-2]x2
    
    d[0] = 1;
    d[1] = 1;
    
    for(int i = 2; i <= 1000; i++) {
        d[i] = (d[i-1]%MOD + (d[i-2]*2)%MOD)%MOD;
    }
        
    cout << d[n] << endl;
    
    return 0;
}
