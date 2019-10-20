#include <iostream>
#include <string.h>
using namespace std;

// variables
int n;
int cache[1001];
const int MOD = 10007;

// functions
int go(int k)
{
    int& ret = cache[k];
    if(ret != -1) return ret;
    if(k == 0 || k == 1) return 1;
    return ret = (go(k-1)%MOD + go(k-2)%MOD)%MOD;    
}

int main()
{
    // init
    memset(cache, -1, sizeof(cache));
    // input
    cin >> n;
    
    // algorithm
    // d[n] : 2*n 타일을 2*1, 1*2 블럭으로 채우는 방법의 수
    // d[n] = d[n-1] + d[n-2]
        
    cout << go(n) << endl;
    
    return 0;
}
