#include <iostream>
#include <algorithm>
using namespace std;

// variables
int N;
int K;
int a[50001];
int s[50001];

// functions


int main()
{
    // init
    s[0] = 0;
    // input
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        // pre processing
        s[i] = s[i-1] + a[i];        
    }
    cin >> K;
    
    // algorithm
    // 소형기관차가 끌 수 있는 객차의 수는 모두 동일
    // 최대한 많은 손님을 옮겨야 함.
    // 번호가 연속적으로 이어진 객차를 끔.
    // 소형 기관차가 최대로 끌 수 있는 객차는 기관차가 끌고 가던 객차 수의 1/3보다 적다.
    // -> 각 세대는 모두 K개의 객차를 끈다고 생각하면 됨.
    // N개 중 K개를 선택하는 문제.(3개로 그루핑)
    
    int ret = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = i+K; j <= N; j++) {
            for(int k = j+K; k <= N; k++) {
                ret = max(ret, (s[i+K-1]-s[i-1])+(s[j+K-1]-s[j-1])+(s[k+K-1]-s[k-1]));
            }
        }
    }
    
    cout << ret << endl;
    return 0;
}
