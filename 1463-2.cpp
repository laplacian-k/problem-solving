#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// variables
int N;
const int inf = 100000000;
int cache[1000001];

int go(int n)
{
    int& ans = cache[n];
    if(ans != -1)  return ans;
    
    if(n == 1) return 0;
    
    int ret = inf;
    if(n%3 == 0) {
        ret = min(ret, go(n/3));
    }
        
    if(n%2 == 0) {
        ret = min(ret, go(n/2));
    }
    
    ret = min(ret, go(n-1));
    
    return ans = (ret + 1);
}

int main()
{
    // init
    memset(cache, -1, sizeof(cache));
    
    // input
    cin >> N;
    
    // algorithm
    cout << go(N) << endl;
    
    return 0;
}
