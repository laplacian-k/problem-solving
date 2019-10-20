#include <iostream>
using namespace std;

// variables
int N;
int d[100001];
const int inf = 100000000;
int main()
{
    // init
    for(int i = 0; i <= 100000; i++) {
        d[i] = inf;
    }
    
    // input
    cin >> N;
    
    // algorithm
    // d[i] = i를 제곱수의 합으로 나타냈을 때 필요한 최소항의 개수
    // d[i] = min(d[i-j^2]+1) (1<= j^2 <= i)
    d[0] = 0;    // 0으로 넣지 않으면 반복문에서 d[0]가 나올 경우 inf+1과 비교하게 된다.
    d[1] = 1;
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j*j <= i; j++) {
            if(d[i] > d[i-j*j] + 1) {
                d[i] = d[i-j*j] + 1;
            }
        }
    }
    
    cout << d[N] << endl;

    return 0;
}
