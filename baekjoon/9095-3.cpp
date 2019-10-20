#include <iostream>
#include <string.h>
using namespace std;

// variables
int n;
int cache[12];

// functions
int go(int k)
{
    int& ret = cache[k];
    if(ret != -1) return ret;
    if(k < 0) return 0;
    if(k == 0) return 1;
    return ret = go(k-1) + go(k-2) + go(k-3);
}

int main()
{
    int T;
    cin >> T;
    
    while(T--) {
        // init
        memset(cache, -1, sizeof(cache));
        // input
        cin >> n;    
        cout << go(n) << endl;
    }
    
    return 0;
}
