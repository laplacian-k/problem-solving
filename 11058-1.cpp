#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// variables
int N;
long long cache[101][2];
long long buffer;
long long n;

// functions
// d[누른버튼개수][현재상태]
// d[n][0] = max(d[n+1][0]+1, d[n+2][1]) (if possible index)
// d[n][1] = max(d[n+1][0]+1, d[n+1][1]+buffer) (if possible index)
long long kriii(int d, int state)
{
    cout << d << ", " << state << ", " << buffer << ", " << n << endl;
    //cout << d << ", " << state << endl;
    long long& ans = cache[d][state];
    if(ans != -1) return ans;
   
    if(d < N)
    long long ret = 0;
    
    // 버퍼 유무에 상관없이 A를 쓸 수 있다.
    n += 1;
    ret = max(ret, kriii(d+1, 0)+1);    // 버퍼를 비워버림.
    n -= 1;
    
    // 버퍼가 없다면
    if(state == 0) {
        if(d+2 < N) {
            int temp = buffer;
            buffer = n;
            // buffer 올리기
            ret = max(ret, kriii(d+2, 1));
            buffer = temp;            
        }

    }
    // 버퍼가 있다면
    else {
        if(d+1 < N) {
            // 붙여넣기
            n += buffer;
            ret = max(ret, kriii(d+1, 1)+buffer);
            n -= buffer;            
        }

    }
    
    return ans = ret;
}


int main()
{
    // init
    buffer = 0;
    n = 0;
    memset(cache, -1, sizeof(cache));
    // input
    cin >> N;
    
    // algorithm
    // 상태를 정의
    // d[누른버튼개수][현재상태]
    // d[n][0] = max(d[n+1][0]+1, d[n+2][1]) (if possible index)
    // d[n][1] = max(d[n+1][0]+1, d[n+1][1]+buffer) (if possible index)
    
    long long ret = 0;
    ret = kriii(0, 0);
    cout << ret << endl;
    
    return 0;
}
