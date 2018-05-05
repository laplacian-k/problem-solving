#include <iostream>
#include <string>
#include <set>
using namespace std;

// variables
int N, L;
string w[2000];
bool a[26][2000];
set<string> s;

string ans;
bool canSolve;

void go(int d, string ret)
{
    if(canSolve) return;
    if(d >= L) {
        // if can use, answer return
        if(s.find(ret) == s.end()){
            ans = ret;
            canSolve = true;
        }
        
        return;
    }
    
    for(int i = 0; i < 26; i++) {
        if(a[i][d]) go(d+1, ret+char(i+'A'));
    }
    
    return;
    
}

int main()
{
    int T;
    cin >> T;
    for(int tests = 1; tests <= T; tests++) {
        
        // init
        ans = "";
        canSolve = false;
        s.clear();
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 2000; j++) {
                a[i][j] = false;
            }
        }
        
        // input
        cin >> N >> L;
        for(int i = 0; i < N; i++) {
            cin >> w[i];
            
            for(int j = 0; j < L; j++) {
                a[w[i][j]-'A'][j] = true;
            }
            
            s.insert(w[i]);
        }
        
        
        cout << "Case #" << tests << ": ";
        if(N == 1 || L == 1) {cout << char(45) << "\n"; continue;}
        
        // algorithm
        go(0, "");
        
        if(!canSolve) cout << char(45) << "\n";
        else cout << ans << "\n";
    }
    
    return 0;
}
