#include <iostream>
#include <algorithm>
using namespace std;

// variables
int N;
int t[16];
int p[16];

// functions
// 1일부터 N일까지 OX로 선택하는 문제.
int solve(int i)
{
    if(i > N) return 0;
    
    int ret = 0;    
    // i번째 상담을 하는 경우
    // i번째 상담이 끝나는 날짜가 N일 이하여야 함.
    if(i+t[i]-1 <= N)
        ret = max(ret, p[i]+solve(i+t[i]));
    
    // i번째 상담을 하지 않는 경우
    ret = max(ret, solve(i+1));    
    
    return ret;
}
int main()
{
    // input
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> t[i] >> p[i];
    }
    
    // algorithm
    int ret = 0;
    ret = solve(1);
    cout << ret << endl;
}
