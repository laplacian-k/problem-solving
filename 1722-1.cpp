#include <iostream>
using namespace std;

// variables
int N;
int dvsn;
int k;
int p[21];

int main()
{
    // input
    cin >> N;
    cin >> dvsn;
    
    if(dvsn == 1) {
        // k번째 수열을 출력
        cin >> k;
    }
    else if(dvsn == 2) {
        // 해당 수열이 몇번째인지 출력
        for(int i = 0; i < N; i++) {
            cin >> p[i];
        }
        
        // algorithm
        // p[x] 미만의 숫자 중 사용가능한 숫자의 개수 x (x(자리수)-1)! + 1(보정값)
        int ret = 0;
        for(int i = 0; i < N; i++) {
            
        }
        
        cout << ret << endl;
    }
    
    return 0;    
}
