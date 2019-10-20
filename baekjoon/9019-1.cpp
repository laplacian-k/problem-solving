#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

// variables
const string comm[4] = {"D", "S", "L", "R"};

// functions

int convert(string command, int cur)
{
    int ret = cur;
    
    // D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
    // S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
    // L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
    // R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
    if(command == "D") {
        ret = 2*ret;
        if(ret > 9999) ret %= 10000;
    }
    else if(command == "S") {
        if(ret == 0) ret = 9999;
        else ret = ret - 1;
    }
    else if(command == "L") {
        // 1234->2341        
        ret = (cur%1000)*10 + cur/1000;
    }
    else if(command == "R") {
        // 1234->4123
        ret = (cur%10)*1000 + (cur/10);
    }
    
    return ret;
}

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
        vector<pair<int, string> > from(10000);
        queue<int> q;
        q.push(a);
        visit[a] = true;
        from[a] = make_pair(-1, "");
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            // D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
            // S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
            // L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
            // R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
            for(int i = 0; i < 4; i++) {
                int next = convert(comm[i], cur);
                // 방문하지 않았다면
                if(!visit[next]) {
                    visit[next] = true;
                    q.push(next);
                    from[next] = make_pair(cur, comm[i]);
                }
            }
        }
        
        // 최소한의 명령어를 출력
        // B부터 from으로 추적하면서 command를 출력!
        stack<string> ans;
        int cur = b;
        string cur2 = "";
        while(cur != -1) {
            ans.push(cur2);
            cur2 = from[cur].second;
            cur = from[cur].first;            
        }
        
        while(!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
    
    return 0;
}
