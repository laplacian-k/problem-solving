#include <iostream>
#include <string.h>
using namespace std;

// variables
int N;
int cache[100001];
const int inf = 100000000;

// functions
int go(int i)
{
    int& ans = cache[i];
    if(ans != inf) return ans;
    if(i == 0) return 0;
    if(i == 1) return 1;
    
    int ret = inf;
    for(int j = 1; j*j <= i; j++) {
        int temp = go(i-j*j) + 1;
        if(ret > temp) {
            ret = temp;
        }
    }
    
    return ans = ret;
}
int main()
{
    // init
    for(int i = 0; i <= 100000; i++) {
        cache[i] = inf;
    }
    
    // input
    cin >> N;
    
    // algorithm
    // d[i] = i를 제곱수의 합으로 나타냈을 때 필요한 최소항의 개수
    // d[i] = min(d[i-j^2]+1) (1<= j^2 <= i)
        
    cout << go(N) << endl;

    return 0;
}
