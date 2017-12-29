#include <iostream>
using namespace std;

// variables
int n;
int d[12];

int main()
{
    int T;
    cin >> T;
    
    // algorithm
    // d[n] = n을 1, 2, 3의 더하기 조합으로 만드는 방법의 수
    // d[n] = d[n-1] + d[n-2] + d[n-3]
    d[0] = 1;
    d[1] = 1;
    for(int i = 2; i <= 11; i++) {
        // 음수 인덱스를 처리하려다보니 2차원 dp꼴이 나타남
        //d[i] = d[i-1] + d[i-2] + d[i-3];
        for(int j = 1; j <= 3; j++) {
            if(i-j < 0) continue;
            d[i] += d[i-j];
        }
    }
    
    while(T--) {
        // input
        cin >> n;
    
        cout << d[n] << endl;
    }
    
    return 0;
}
