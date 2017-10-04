#include <iostream>
using namespace std;

// variables
int n, m;
int wall[50][50];
int main()
{
    // input
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> wall[i][j];
        }
    }
    
    // algorithm
    // dfs로 찾아가면서 막힐 때까지 1, 2, 3, ... 번 영역으로 나눠줌.
    // 이때 동시에 넓이도 구해둠.
    // 막힌 벽을 전부 한 번씩 뚫고, 그 때마다 가장 큰 영역의 크기를 구함.
}
