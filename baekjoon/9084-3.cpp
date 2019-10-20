#include <iostream>
#include <string.h>
using namespace std;

// variables;
int N;
int coin[20];
int M;
int d[10001];

int main()
{
    int test_case;
    cin >> test_case;
    for(int tc = 0; tc < test_case; tc++) {
    	// init
        memset(d, 0, sizeof(d));
        // input
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> coin[i];
        }
        cin >> M;
        
        // algorithm
        // 주어진 M원을 만들 수 있는 모든 경우의 수를 센다.
        d[0] = 1;
        // 1번 동전부터 모두 만들어보고, 2번 동전부터 모두 만들어보고, .... n번 동전까지 순서대로 만듦
        for(int i = 0; i < N; i++) {
            for(int j = coin[i]; j <= M; j++) {
                d[j] += d[j-coin[i]];
            }
        }
        
        cout << d[M] << endl;
    }
}
