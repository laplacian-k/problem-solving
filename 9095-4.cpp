#include <iostream>
using namespace std;

// variables
int n;

// functions
int go(int sum)
{
    if(sum > n) return 0;
    if(sum == n) return 1;
    int ret = 0;
    for(int i = 1; i <= 3; i++) {
        ret += go(sum+i);
    }    
    return ret;
}

int main()
{
    int T;
    cin >> T;    
    while(T--) {
        // input
        cin >> n;
        // algorithm
        // n을 1,2,3의 합으로 나타내는 방법의 수
        int ret = 0;    // 3^11
        ret = go(0);
        cout << ret << '\n';
    }    
    
    return 0;
}
