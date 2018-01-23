#include <iostream>
using namespace std;

// variables
int N;
int dvsn;
int k;
int p[21];
bool visit[21];
int fact[21];

int main()
{
    // init
    fact[0] = 1;
    for(int i = 0; i < 21; i++) {
        visit[i] = false;
        if(i == 0) continue;
        fact[i] = i*fact[i-1];
    }
    // input
    cin >> N;
    cin >> dvsn;
    
    if(dvsn == 1) {
        // k번째 수열을 출력
        cin >> k;
        
        // algorithm
        // 전체 N!
        // k <= (x(자리수)-1)! 면 확정
        // 아니라면 (x-1)!을 더해줌.
        
        // 전체 4!
        // 3 <= 3! visit[1]
        // 3 <= 2! 아니라면 3 <= 2*2! visit[3], 3-1*2! = 1
        // 1 <= 1! visit[2]
        
        for(int x = N; x >= 1; x--) {
            int val = 1;
            for(int i = 1; i <= N; i++) {
                if(visit[i]) continue;
                if(k <= val*fact[x-1]) {
                    visit[i] = true;
                    cout << i << ' ';
                    k -= (val-1)*fact[x-1];
                    break;
                }
                else {
                    val += 1;
                }
                
            }
            
        }
    }
    else if(dvsn == 2) {
        // 해당 수열이 몇번째인지 출력
        for(int i = 0; i < N; i++) {
            cin >> p[i];
        }
        
        // algorithm
        // p[x] 미만의 숫자 중 사용가능한 숫자의 개수 x (x(자리수)-1)! + 1(보정값)
        // 1324
        // 0*3!+1*2!+0*1!
        // {1, 3}
        int ret = 0;
        for(int x = 0; x < N-1; x++) {
            int val = 0;
            for(int i = 1; i < p[x]; i++) {
                
                if(!visit[i]) val++;
            }            
            ret += (val*fact[N-x-1]);
            //cout << val << "*" << fact[N-x-1] << '\n';
            visit[p[x]] = true;
            //cout << "visit[" << p[x] << "]" << '\n';
        }
        
        ret += 1;
        
        cout << ret << endl;
    }
    
    return 0;    
}
