#include <iostream>
using namespace std;

// variables
int N;
const long long MOD = 987654321;
long long D[10001];

// functions

int main()
{
    // input
    cin >> N;
    
    // algorithm
    // D[N] = N명이 완벽한 악수를 하는 경우의 수
    // D[N] = sigma(D[N-i]*D[i-2]) (2 <= i <= N 단, i는 짝수)
    //int ret = 0;
    D[0] = 1;
    for(int j = 2; j <= N; j += 2) {
        for(int i = 2; i <= j; i += 2) {
            D[j] += ((D[j-i]%MOD)*(D[i-2]%MOD))%MOD; 
        }        
    }    
    cout << D[N] << endl;
    
    return 0;
}
