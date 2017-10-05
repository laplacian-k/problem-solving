#include <iostream>
using namespace std;

// variables
int n, m;
int wall[50][50];
int room[50][50];
int cnt = 0;
int roomSize[2501];


//functions
void dfs(int y, int x)
{
    // validation checking
    if( !((0 <= y && y < m) && (0 <= x && x < n)) )
       return;
    if(room[y][x] != -1)
       return;
    // 방 번호로 마킹함.
    room[y][x] = cnt;
    // 방 크기를 늘려감.
    roomSize[cnt] += 1;
    
    
    // 벽에 대한 정보는 비트마스크로 해석
    int w = wall[y][x];
    // 서쪽에 벽이 있을 때는 1을, 북쪽에 벽이 있을 때는 2를, 동쪽에 벽이 있을 때는 4를, 남쪽에 벽이 있을 때는 8을 더한 값이 주어진다

    if((w & (1<<0)) == 0)
        dfs(y, x-1);
    
    if((w & (1<<1)) == 0)
        dfs(y-1, x);
    
    if((w & (1<<2))== 0)
        dfs(y, x+1);
    
    if((w & (1<<3)) == 0) 
        dfs(y+1, x);
       
    return;
}


int main()
{
    // input
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> wall[i][j];
            // init
            room[i][j] = -1;
        }
    }
    // init
    for(int i = 0; i < 2500; i++)
        roomSize[i] = 0;
    
    // algorithm
    // dfs로 찾아가면서 막힐 때까지 1, 2, 3, ... 번 영역으로 나눠줌.
    cnt = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(room[i][j] == -1) {
                cnt++;
                dfs(i, j);                
            }
        }
    }
    // 이때 동시에 넓이도 구해둠.
    int ret1 = 0;
    for(int i = 1; i <= cnt; i++)
        ret1 = max(ret1, roomSize[i]);
        
    // 막힌 벽을 전부 한 번씩 뚫고, 그 때마다 가장 큰 영역의 크기를 구함.
    int ret2 = 0;
    for(int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++) {
            // 벽을 찾자.
            // 서쪽에 벽이 있을 때는 1을, 북쪽에 벽이 있을 때는 2를, 동쪽에 벽이 있을 때는 4를, 남쪽에 벽이 있을 때는 8을 더한 값이 주어진다
            int w = wall[y][x];
            if((w & (1<<0)) == 1) {
                int ny = y;
                int nx = x-1;
                if((0 <= ny && ny < m) && (0 <= nx && nx < n) && (room[y][x] != room[ny][nx])){
                    int num1 = room[y][x];
                    int num2 = room[ny][nx];
                    ret2 = max(ret2, roomSize[num1]+roomSize[num2]);
                }
            }
            if((w & (1<<1)) == 2) {
                int ny = y-1;
                int nx = x;
                if((0 <= ny && ny < m) && (0 <= nx && nx < n) && (room[y][x] != room[ny][nx])){
                    int num1 = room[y][x];
                    int num2 = room[ny][nx];
                    ret2 = max(ret2, roomSize[num1]+roomSize[num2]);
                }
            }
            if((w & (1<<2)) == 4) {
                int ny = y;
                int nx = x+1;
                if((0 <= ny && ny < m) && (0 <= nx && nx < n) && (room[y][x] != room[ny][nx])){
                    int num1 = room[y][x];
                    int num2 = room[ny][nx];
                    ret2 = max(ret2, roomSize[num1]+roomSize[num2]);
                }
            }
            if((w & (1<<3)) == 8) {
                int ny = y+1;
                int nx = x;
                if((0 <= ny && ny < m) && (0 <= nx && nx < n) && (room[y][x] != room[ny][nx])){
                    int num1 = room[y][x];
                    int num2 = room[ny][nx];
                    ret2 = max(ret2, roomSize[num1]+roomSize[num2]);
                }
            }
        }
    }
    
    cout << cnt << endl;
    cout << ret1 << endl;
    cout << ret2 << endl;
