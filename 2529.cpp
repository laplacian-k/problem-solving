#include <iostream>
#include <string>
using namespace std;

// variables
int k;
string ieq[10];
const long long inf = 10000000000;
bool u[10];

string ret1;    // 최소값
string ret2;    // 최대값

long long a = inf;
long long b = -1;

// functions
void solve(int cur, int d, string n)
{
    // k+1자리가 되었을 때 최대 최소 판단
    if(d == k+1) {
        // cout << n << endl;
        long long conv_n = stoll(n);
        
        if(b < conv_n){
            b = conv_n;
            ret2 = n;
        }
        if(a > conv_n){
            a = conv_n;
            ret1 = n;
        }
    }
    
    for(int next = 0; next < 10; next++) {
        if(cur == -1) {
            u[next] = true;
            solve(next, d+1, to_string(next));
            u[next] = false;
            continue;
        }
        if(u[next]) continue;
        u[next] = true;
        if(ieq[d] == "<" && (cur < next))
            solve(next, d+1, n+to_string(next));
        if(ieq[d] == ">" && (cur > next))
            solve(next, d+1, n+to_string(next));
        u[next] = false;
    }
}

int main()
{
    // init
    ret1 = "";
    ret2 = "";
    for(int i = 0; i < 10; i++)
        u[i] = false;
    // input
    cin >> k;
    for(int i = 1; i <= k; i++)
        cin >> ieq[i];
    
    // algorithm
    // k+1자리 숫자를 만듦(이때 부등호 성립하는 숫자들의 조합으로 만듦)
    // 정답을 리턴받을 때마다 최소값과 최대값을 갱신해 나감.
    solve(-1, 0, "");
    
    cout << ret2 << endl;
    cout << ret1 << endl;
    
}
