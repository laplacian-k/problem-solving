#include <cstdio>
#include <cstring>

// variables
int M;
int ans;

int main()
{
    // init
    ans = 0;    // 공집합
    
    // input
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        char c[20];
        int x;
        scanf("%s", c);
        if(c[1] == 'l' || c[0] == 'e') {
            x = 0;
        }
        else {
            scanf("%d", &x);
            x--;
        }
        // algorithm
        // add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
        // remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
        // check x: S에 x가 있으면 1을, 없으면 0을 출력한다.
        // toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
        // all: S를 {1, 2, ..., 20} 으로 바꾼다.
        // empty: S를 공집합으로 바꾼다.
    
        if(c[1] == 'd') {
            ans |= (1<<x);
        }
        else if(c[0] == 'r') {
            ans &= ~(1<<x);
        }
        else if(c[0] == 'c') {
            if(ans&(1<<x)) printf("%d\n", 1);
            else printf("%d\n", 0);
        }
        else if(c[0] == 't') {
            ans ^= (1<<x);
        }
        else if(c[1] == 'l') {
            ans = (1<<20)-1;
        }
        else if(c[0] == 'e') {
            ans = 0;
        }        
        //cout << comm << ", " << n << endl;
        
    }
    
    return 0;
}
