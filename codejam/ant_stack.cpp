#include <iostream>
using namespace std;

// variables
int N;
int w[500];

bool go(int cur, int last, int base, int sum)
{
    if(cur != -1 && sum <= base) {
        cout << sum << "vs" << base << endl;
        return true;
    }
    
    for(int i = cur+1; i < last; i++) {
        go(i, last, base, sum+w[i]);
    }
    
    return false;
}

int main()
{
    int T;
    cin >> T;
    for(int tests = 1; tests <= T; tests++) {
        // input
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> w[i];
        }
        
        cout << "Case #" << tests << ": ";
        // algorithm
        int ret = 0;
        for(int i = N-1; i >= 0; i--) {
            int base = w[i]*6;
            bool isPossible = go(-1, i-1, base, 0);
            if(isPossible) ret++;
            
        }
        cout << ret << endl;
        
    }
    
    return 0;
}
