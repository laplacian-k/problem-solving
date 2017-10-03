#include <iostream>
#include <algorithm>
using namespace std;

// variables
int N;
struct data {
    int term;
    int profit;
};
data A[16];
bool pre[16];
bool cs[16];

// functions
// 최대 depth는 15
int solve(int cur, int sum)
{
    // 끝에 도달했다면 정답을 리턴
    if(cur == N+1)
        return sum;
    // 불가능하다면 다음으로 넘김
    if(!pre[cur] || !cs[cur])
        return solve(cur+1, sum);
    int ret = 0;
    
    // 선택
    // 현재 일자부터 해당 기간까지의 상담은 불가능
    for(int i = cur; i < cur+A[cur].term; i++)
        cs[i] = false;
    ret = max(ret, solve(cur+1, sum+A[cur].profit));
    for(int i = cur; i < cur+A[cur].term; i++)
        cs[i] = true;
    // 선택 x
    ret = max(ret, solve(cur+1, sum));
        
    return ret;
}

int main()
{
    // init
    for(int i = 0; i <= 16; i++) {
        pre[i] = true;
        cs[i] = true;
    }
    // input
    cin >> N;
    for(int i = 1; i <= N; i ++) {
        cin >> A[i].term >> A[i].profit; 
        
        // pre processing
        if(i+A[i].term-1 > N)
            pre[i] = false;
    }
    
    int ret = 0;
    
    // algorithm
    // 상담을 하면 현재 일자 포함, Ti만큼의 상담은 할 수 없음.
    // N일을 벗어나도 상담을 할 수 없음. (불가능한 것은 미리 false 처리)
    ret = solve(1, 0);
    
    cout << ret << endl;
}
