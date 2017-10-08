#include <iostream>
using namespace std;

// variables;
int N;
int coin[20];
int M;

// functions
int solve(int index, int sum)
{
	if (index == N) {
		if (sum == M) return 1;
		else return 0;
	}
    
    int ret = 0;
    // i번째 동전을 x개 사용!
    for(int x = 0; x*coin[index] <= M; x++) {
        ret += solve(index+1, sum+x*coin[index]);
    }
    
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
