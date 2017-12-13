#include <iostream>
using namespace std;

// variables
int N;
bool visit[21];

// functions
long long go(int cur, int next_status)
{
    // 전부 배치했다면 경우의 수 카운트
    if()
        return 1;
    
    long long ret = 0;
    
    for(int next = 1; next <= N; next++) {
        // 사용했다면 skip
        if(visit[next]) continue;
        
        visit[next] = true;
        // status에 따라 다음에 배치가능한 인원을 찾는다.
        // 커야한다면
        if(next_status == 1 && cur < next) {
            ret += go(next, 0);          
        }
        // 작아야한다면
        if(next_status == 0 && cur > next) {
            ret += go(next, 1);
        }   
        
        visit[next] = false;       
    }
    
    return ret;
}

int main()
{
    int T;
    cin >> T;
    for(test_case = 0; test_case < T; test_case++) {
        // init
        for(int i = 0; i <= 20; i++) {
            visit[i] = false;
        }
        // input
        cin >> N;
        
        // algorithm
        long long ret = 0;
        ret = go(0, -1);
        cout << ret << endl;
        
    }
    return 0;
}
