#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// variables
int L, C;

// functions
void go(vector<string>& d, int cur, int dep, int m, string ans)
{
    //if(dep > L) return;
    if(dep == L) {
        if(m >= 1 && (L-m) >= 2) {
            // 정답 출력
            cout << ans << '\n';
        }
        return;
    }
    
    for(int next = cur+1; next < C; next++) {
        if(d[next] == "a" || d[next] == "e" || d[next] == "i" || d[next] == "o" || d[next] == "u")
            go(d, next, dep+1, m+1, ans+d[next]);
        else
            go(d, next, dep+1, m, ans+d[next]);
    }
    
    return;
}

int main()
{
    // input
    cin >> L >> C;
    vector<string> d(C);
    for(int i = 0; i < C; i++) {
        // char ch;
        //cin >> ch;
        //d[i] = ch-'a';
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    
    //cout << L << ' ' << C << '\n';
    //for(int i = 0; i < C; i++) {
    //    cout << d[i] << ' ';
    //}    
    //cout << '\n';
    
    go(d, -1, 0, 0, "");
    
    return 0;
}
