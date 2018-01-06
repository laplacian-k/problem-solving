#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

// variables
string A, B;
const string comm[4] = {"D", "S", "L", "R"};

// functions
string convert(int a) {
    string ret = "";
    
    ret = to_string(a);
    int len = ret.length();
    
    if(len == 3) ret = "0" + ret;
    if(len == 2) ret = "00" + ret;
    if(len == 1) ret = "000" + ret;
    
    return ret;
}

string reg(string command, string cur)
{
    int ret = stoi(cur);
    
    // D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
    // S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
    // L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
    // R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
    if(command == "D") {
        ret = 2*ret;
        if(ret > 9999) ret %= 10000;
        
        return convert(ret);
    }
    else if(command == "S") {
        if(ret == 0) ret = 9999;
        else ret = ret - 1;
        
        return convert(ret);
    }
    else if(command == "L") {
        char temp = cur[0];
        for(int i = 0; i <= 2; i++) {
            cur[i] = cur[i+1];
        }
        cur[3] = temp;
        
        return cur;
    }
    else if(command == "R") {
        
        char temp = cur[3];
        for(int i = 3; i >= 1; i--) {
            cur[i] = cur[i-1];
        }        
        cur[0] = temp;
        
        return cur;
    }
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
        // cout << A << " " << B << endl;
        
        // pre processing
        A = convert(a);
        B = convert(b);
        // cout << "convert!" << endl;
        // cout << A << " " << B << endl;
        
        
        // algorithm
        
        vector<bool> visit(10000, false);
        vector<pair<int, string> > from(10000);
        queue<string> q;
        q.push(A);
        visit[stoi(A)] = true;
        from[stoi(A)] = make_pair(-1, "");
        
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            
            // D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
            // S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
            // L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
            // R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
            for(int i = 0; i < 4; i++) {
                string next = reg(comm[i], cur);
                // 방문하지 않았다면
                if(!visit[stoi(next)]) {
                    // cout << next << endl;
                    visit[stoi(next)] = true;
                    q.push(next);
                    from[stoi(next)] = make_pair(stoi(cur), comm[i]);
                }
            }
        }
        
        // 최소한의 명령어를 출력
        // B부터 from으로 추적하면서 command를 출력!
        stack<string> ans;
        int cur = stoi(B);
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
