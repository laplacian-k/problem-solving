#include <iostream>
using namespace std;

// variables
int N;
int A[1000001];
int B, C;

int main()
{
    // input
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }   
    cin >> B >> C;
    
    // algorithm
    long long ret = 0;
    for(int i = 1; i <= N; i++) {
        // 한 방에 필요한 최소 감독관 수를 더해감.
        int base = A[i];
        base = base - B;
        ret += 1;
        int a = 0;
        if(base > 0) {
            a = base / C;
            if(a*C != base)
                a += 1;            
            ret += a;
        }   
        
            
    }
    
    cout << ret << endl;
}
