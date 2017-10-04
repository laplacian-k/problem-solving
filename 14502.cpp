#include <iostream>
using namespace std;

// variables
int N, M;
int map[8][8];
int safe = 0;
// functions
bool validation(int y, int x)
{
    if((0 <= y && y < N) && (0 <= x && x < M)) return true;
    return false;
}
int virus(int y, int x)
{
    int ny = 0;
    int nx = 0;
    
    int ret = 0;
    // 네 방향에 대해 모두 탐색
    // validation checking 해야함.
    // 상
    ny = y-1;
    nx = x;    
    if(validation(ny, nx) && map[ny][nx] == 0) {
        map[ny][nx] = 2;
        ret = ret + 1 + virus(ny, nx);
    }
    // 하
    ny = y+1;
    nx = x;
    if(validation(ny, nx) && map[ny][nx] == 0) {
        map[ny][nx] = 2;
        ret = ret + 1 + virus(ny, nx);
    }
    // 좌
    ny = y;
    nx = x-1;
    if(validation(ny, nx) && map[ny][nx] == 0) {
        map[ny][nx] = 2;
        ret = ret + 1 + virus(ny, nx);
    }
    // 우
    ny = y;
    nx = x+1;
    if(validation(ny, nx) && map[ny][nx] == 0) {
        map[ny][nx] = 2;
        ret = ret + 1 + virus(ny, nx);
    }
    
    return ret;
}

int selection(int depth)
{
    if(depth > 3)
    {
        int sum = 0;
        // 바이러스를 퍼트려서 도달하는 영역을 모두 계산
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[i][j] == 2)
                    sum += virus(i, j);
            }
        }
        return safe - sum;
    }
    int ret = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0) {
                map[i][j] = 1;
                ret = max(ret, selection(depth+1));
                map[i][j] = 0;
            }
        }
    }
    
    return ret;
}
int main()
{
    // init
    safe = 0;
    // input
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            // pre processing
            if(map[i][j] == 0) safe += 1;
        }
    }
    
    int ret = 0;
    // algorithm
    // 빈칸인 곳 3개를 선택함.
    safe = safe - 3;
    
    // 바이러스를 퍼트림.
    // 정답은 최대여야 하므로 virus 영역은 최소여야 한다.
    ret = selection(1);
    
    cout << ret << endl;
}
