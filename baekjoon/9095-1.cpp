#include<iostream>
#include<string.h>
using namespace std;

// variables
int n;
int d[11];

int main()
{
    int test_case;
    cin >> test_case;
    for(int tc = 0; tc < test_case; tc++) {
        // init
        memset(d, 0, sizeof(d));
        
        // input
        cin >> n;
        
        // algorithm
        // n을 1, 2, 3의 합으로 나타내는 방법의 수
        d[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <=3; j++) {
                if(i-j < 0) continue;
                d[i] += d[i-j];
            }
        }
        cout << d[n] << endl;
    }
}
