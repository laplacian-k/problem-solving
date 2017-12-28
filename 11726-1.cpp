#include <iostream>
using namespace std;

// variables
int n;
int d[1001];
const int MOD = 10007;

int main()
{
    // input
    cin >> n;
    
    // algorithm
    // d[n] : 2*n 타일을 2*1, 1*2 블럭으로 채우는 방법의 수
    // d[n] = d[n-1] + d[n-2]
    d[1] = 1;
    d[2] = 2;
    
    for(int i = 3; i <= 1000; i++) {
        d[i] = (d[i-1]%MOD + d[i-2]%MOD)%MOD;
    }
    
    cout << d[n] << endl;
    
    return 0;
}
