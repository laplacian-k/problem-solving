#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// variables
int n;
int forest[500][500];
const int dy[] = {-1, 1, 0, 0};    // 상하좌우
const int dx[] = {0, 0, -1, 1};
int cache[500][500];

// functions
int go(int y, int x)
{
    int& ans = cache[y][x];
    if(ans != -1) return cache[y][x];
    
    int ret = 1;    // 갈 곳이 없으면 1일
    int temp = forest[y][x];
    // 지금 현 위치보다 대나무가 많은 곳으로만 이동함.
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        // 숲을 벗어나면 가지 않음.
        if(!((0 <= ny && ny < n) && (0 <= nx && nx < n))) continue;
        // 현 위치보다 먹이가 많을 때만 이동!
        if(forest[y][x] < forest[ny][nx] ) {            
            forest[y][x] = 0;    // 대나무를 먹음.
            ret = max(ret, 1 + go(ny, nx));
            forest[y][x] = temp;
        }            
    }
    
    return ans = ret;
}

int main()
{
    // init
    memset(cache, -1, sizeof(cache));
    
    // input
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> forest[i][j];
        }
    }
    /*
    cout << n << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << forest[i][j] << " ";
        }
        cout << endl;
    } 
    */
    
    // algorithm
    int ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 시작점
            ret = max(ret, go(i, j));
        }
    }
    cout << ret << endl;
    
    return 0;
}
