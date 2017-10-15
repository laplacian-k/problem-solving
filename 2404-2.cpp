#include <iostream>
using namespace std;

// variables
int p, q, a, n;

// functions
long long gcd(long long x, long long y)
{
    if(y == 0) return x;
    else return gcd(y, x%y);
}

long long unit(int p, int q, int d, int m, int cur)
{
    //if(m > a) return 0;
    if(d > n) return 0;
    // 가지치기 하나 더 필요함.
    // 사용할 수 있는 가장 큰 단위분수를 남은 depth만큼 사용하더라도 p/q를 못 만든다면
    // p/q > (n-d)/cur
    if(p*cur > (n-d)*q) return 0;
    
    // p/q-1/x = 0 이라면 정답
    // p*x-q/q*x = 0
    if(p == 0) return 1;
    
    long long ret = 0;
    // 단위분수 선택
    // next 범위는 a까지 해야함.
    for(int next = cur; next <= a; next++) {
        if(m*next > a) break;
        long long bj = p*next-q;
        long long bm = q*next;
        long long k = gcd(bj, bm);
        bj = bj / k;
        bm = bm / k;    
        ret += unit(bj, bm, d+1, m*next, next);
    }
    return ret;
}

int main()
{
    // input
    cin >> p >> q >> a >> n;
    
    // algorithm
    long long ret = 0;
    ret = unit(p, q, 0, 1, 1);
    cout << ret << endl;
}
