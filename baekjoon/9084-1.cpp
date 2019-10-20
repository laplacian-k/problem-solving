#include <iostream>
using namespace std;

// variables;
int N;
int coin[20];
int M;

//functions
int solve(int index, int sum)
{
    // M이 넘어갔다면 정답 불가능
    if(sum > M) return 0;
    if(sum == M) return 1;
        
    int ret = 0;
    // 동전을 사용
    ret += solve(index+1, sum+coin[index]);
    // 동전을 사용 x
    ret += solve(index+1, sum);
    
    return ret;
}

int main()
{
    int test_case;
    cin >> test_case;
    for(int tc = 0; tc < test_case; tc++) {
        // input
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> coin[i];
        }
        cin >> M;
        
        // algorithm
        // 주어진 M원을 만들 수 있는 모든 경우의 수를 센다.
        int ret = 0;
        ret = solve(0, 0);
        
        cout << ret << endl;
    }
}
