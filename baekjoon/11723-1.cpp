#include <iostream>
#include <string>
using namespace std;

// variables
int M;
int ans;

int main()
{
    ios_base::sync_with_stdio(false); 
    // init
    ans = 0;    // 공집합
    
    // input
    cin >> M;
    for(int i = 0; i < M; i++) {
        string c;
        int x;
        cin >> c;
        if(c == "all" || c == "empty") {
            x = 0;
        }
        else {
            cin >> x;
            x--;
        }
        // algorithm
        // add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
        // remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
        // check x: S에 x가 있으면 1을, 없으면 0을 출력한다.
        // toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
        // all: S를 {1, 2, ..., 20} 으로 바꾼다.
        // empty: S를 공집합으로 바꾼다.
    
        if(c == "add") {
            ans |= (1<<x);
        }
        else if(c == "remove") {
            ans &= ~(1<<x);
        }
        else if(c == "check") {
            if(ans&(1<<x)) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(c == "toggle") {
            ans ^= (1<<x);
        }
        else if(c == "all") {
            ans = (1<<20)-1;
        }
        else if(c == "empty") {
            ans = 0;
        }        
        //cout << comm << ", " << n << endl;
        
    }
    
    return 0;
}
