#include <iostream>
#include <algorithm>    // for reverse
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        // input
        // 0 ~ 9999
        int a, b;
        cin >> a >> b;        
        
        // algorithm        
        vector<bool> visit(10000, false);
        vector<int> from(10000);
        vector<char> how(10000);
        queue<int> q;
        q.push(a);
        visit[a] = true;
        from[a] = -1;
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            // D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
            // S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
            // L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
            // R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
            
            // D
            int next = (cur*2)%10000;
            if(!visit[next]) {
                visit[next] = true;
                q.push(next);
                from[next] = cur;
                how[next] = 'D';
            }
            // S
            next = cur - 1;
            if(cur == 0) next = 9999;
            if(!visit[next]) {
                visit[next] = true;
                q.push(next);
                from[next] = cur;
                how[next] = 'S';
            }
            // L
            next = (cur%1000)*10 + cur/1000;
            if(!visit[next]) {
                visit[next] = true;
                q.push(next);
                from[next] = cur;
                how[next] = 'L';
            }
            // R
            next = (cur%10)*1000 + (cur/10);
            if(!visit[next]) {
                visit[next] = true;
                q.push(next);
                from[next] = cur;
                how[next] = 'R';
            }
        }
        
        // 최소한의 명령어를 출력
        // B부터 from으로 추적하면서 command를 출력!
        
        string ans = "";
        while(b != a) {
            ans += how[b];
            b = from[b];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    
    return 0;
}
