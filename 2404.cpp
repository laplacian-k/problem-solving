#include <iostream>
using namespace std;

// variables
int p, q, a, n;

// functions
int unit(int d, int m)
{
    if(d > 7) return 0;
    
    // p/q = x+y/xy를 본다!
    // p*x*y == q*(x+y)
    int ret = 0;
    for(int i = 1; i <= 800; i++){
        if(m*i > 12000) break;
        ret += unit(d+1, m*i, );
    }
    
    return ret;
}
int main()
{
    // input
    cin >> p >> q >> a >> n;
    
    // algorithm
    int ret = 0;
    //ret = unit(0, 1);
    // where is depth?
    for(int p = 1; p <= 800; p++) {
        for(int q = 1; q <= 800; q++) {
            for(int x = 1; x <= 800; x++) {
                if(q*x > 12000) continue;
                d[p*x+q][q*x] += d[p][q]; 
            }
        }
    }
    //cout << ret << endl;
    cout << d[p][q] << endl;
}
