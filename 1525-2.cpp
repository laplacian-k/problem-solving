#include <iostream>
#include <queue>
using namespace std;

// variables
int a[3][3];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int main()
{
    // input
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    
    // algorithm
    // 이동이 불가능한 경우 -1을 출력한다.
    queue<int> q;
    q.push(a);
    vector<int> dist()
    
    while(!q.empty()) {
        
        // 0의 위치를 찾는다.
        int y = -1;
        int x = -1;
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(a[i][j] == 0) {
                    y = i;
                    x = j;
                }
            }
        }     
        
        // 해당 위치를 기준으로 상하좌우를 탐색한다.
        int ny = -1;
        int nx = -1;
        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            
            // 벗어나면 skip
            if(!((0 <= y && y < 3) && (0<= x && x < 3))) continue;
            // 위치를 바꿈
            a[y][x] = a[ny][nx];
            a[ny][nx] = 0;
            // 갔던 곳이라면 가지 않는다.
            // a[ny][nx]가 이미 나왔다면?
        }
        
        

    }
    
    cout << dist
    
    return 0;
}
