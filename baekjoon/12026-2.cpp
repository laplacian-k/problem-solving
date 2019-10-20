#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// variables
int N;
string s;
const int inf = 1000000000;
int cache[1000];

// functions
char get_next(char prev)
{
    if(prev == 'B')
        return 'O';
    if(prev == 'O')
        return 'J';
    if(prev == 'J')
        return 'B';
}
int go(int cur)
{
    int&ans = cache[cur];
    if(ans != inf) return ans;
    
    // N에 도착한다면
    if(cur == N-1)
        return 0;
    
    int ret = inf;
    for(int next = cur+1; next < N; next++) {
        // 갈 수 있는 곳은 모두 가본다.(B->O, O->J, J->B)
        if(s[next] == get_next(s[cur])) {
            int E = (next-cur)*(next-cur);
            ret = min(ret, go(next)+E);
        }
            
    }
    
    return ans = ret;
}

int main()
{
    // init
    s = "";
    for(int i = 0; i < 1000; i++) {
        cache[i] = inf;
    }
    // input
    cin >> N;
    cin >> s;
    
    // algorithm
    int ret = 0;
    ret = go(0);
    if(ret >= inf) cout << -1 << endl;
    else cout << ret << endl;
    
    return 0;
}
