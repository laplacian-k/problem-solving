#include <iostream>
#include <string.h>
using namespace std;
 
// variables
int N, M;
int mars[1001][1001];
const int low = -1000000000;
int cache[1001][1001][3];
// functions
int solve(int y, int x, int where)    // where 0 : 위 1 : 왼 2 : 오 에서 옴.
{
    int& ret = cache[y][x][where];
    if(ret != -1) return ret;
 
    if(y == N && x == M)
        return mars[N][M];
    if(!((1 <= y && y <= N) && (1 <= x && x <= M)))
        return 0;
    // 최소값을 줘버리면 N, M에 도달하지 못하고 끝날 경우 자동으로 답으로 계산하지 않게 된다. -> where flag를 통해 해결
    // 10^6*(-100)이 최소값.
    int ans = low;
    // 왼쪽
    // 마지막 줄에 도달했으면 왼쪽으로는 갈 수 없음.
    if(where != 1 && y != N)
        ans = max(ans, mars[y][x]+solve(y, x-1, 2));
    // 오른쪽
    if(where != 2)
        ans = max(ans, mars[y][x]+solve(y, x+1, 1));
    // 아래
    ans = max(ans, mars[y][x]+solve(y+1, x, 0));
 
    return ret = ans;
}
int main()
{
    // init
    memset(cache, -1, sizeof(cache));
    // input
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> mars[i][j];
        }
    }
 
    // algorithm
    // 한번 갔던 곳은 다시 가지 않음
    // 왼쪽, 오른쪽, 아래쪽만 이동 가능
    // (1,1)에서 (i,j)까지 이동하는 최대 가치
    // D[i][j] = mars[i][j] + max(D[i-1][j], D[i][j-1], D[i][j+1]) (각 인덱스는 화성 배열의 범위를 벗어나지 않아야 함.)
    // dp로는 일렬로 계산이 불가능해짐. (왼쪽 움직임 때문). 따라서 메모이제이션을 사용
    // 이전에 왼쪽에서 왔으면 왼쪽으로 갈 수 없음
    // 이전에 오른쪽에서 왔으면 오른쪽으로 갈 수 없음.
    int ret = 0;
    // (1,1)에서 (N, M)까지 가는 최대 가치를 구함.
    ret = solve(1, 1, 0);
 
    cout << ret << endl;
}
