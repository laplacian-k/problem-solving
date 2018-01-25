#include<iostream>
#include<algorithm>    // for next_permutation
#include<vector>
using namespace std;

// variables
int N;
int w[11][11];
const int inf = 1000000000;

int main()
{
    // input
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> w[i][j];
        }        
    }    
    
    // algorithm
    // next_permutaion 방식
    
    // N개의 수열을 만듦
    // 1, 2, 3, ... , N
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        a[i] = i+1;
    }
    
    int ret = inf;
    // O(N!*N)
    do {
        // 인접한 두 노드끼리 이동이 가능해야 한다.
        int sum = 0;
        bool canGo = true;
        for(int i = 0; i < N-1; i++) {
            // 하나라도 이동할 수 없다면 종료
            if(w[a[i]][a[i+1]] == 0) {
                canGo = false;
                break;
            }
            sum += w[a[i]][a[i+1]];
        }
        
        // 모든 인접한 노드를 방문 가능하고, 끝 노드에서 처음 노드까지 방문할 수 있다면
        if(canGo && w[a[N-1]][a[0]] != 0) ret = min(ret, sum+w[a[N-1]][a[0]]);
        
    } while(next_permutation(a.begin(), a.end()));
    
    cout << ret << '\n';
    
    return 0;
}
