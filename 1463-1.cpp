#include <iostream>
#include <algorithm>
using namespace std;

// variables
int N;
int d[1000001];
const int inf = 100000000;

int main()
{
    // input
    cin >> N;
    
    // algorithm
    // d[n] = min(d[n/3], d[n/2], d[n-1]) + 1; (2 <= n <= 10^6)
    
    d[1] = 0;
    d[2] = 1;
    for(int i = 3; i <= N; i++) {
        int ret = inf;
        if(i%3 == 0) {
            ret = min(ret, d[i/3]);
        }
        if(i%2 == 0) {
            ret = min(ret, d[i/2]);
        }
        ret = min(ret, d[i-1]);
        
        d[i] = ret + 1;
    }
    cout << d[N] << endl;
    
    return 0;
}
