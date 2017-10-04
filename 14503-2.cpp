#include <iostream>
#include <queue>
using namespace std;

// variables
int N, M;
int map[51][51];
int d;

int main()
{
    // input 1
    cin >> N >> M;
    // init
    // 외곽을 벽(1)으로 처리하기 위해 전체 범위를 1로 초기화
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= M; j++)
            map[i][j] = 1;
    // input 2
    // 현재 위치와 방향이 주어짐
    int y, x;
    cin >> y >> x;
    cin >> d;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> map[i][j];

    
    int ret = 0;
    int a = y;
    int b = x;
    
    while(1) {
        if(map[a][b] == 0) map[a][b] = 2;
        
        // d를 기준으로 왼쪽을 탐색!
        // d : 북(0) 동(1) 남(2) 서(3)
        // 0 : 빈칸 1 : 벽 2 : 청소함.
        // d를 기준으로 왼쪽 탐색, 청소 공간 있으면 push 없으면 d 회전
        //cout << map[a][b-1] << ", " << map[a+1][b] << ", " << map[a][b+1] << ", " << map[a-1][b] << endl;
        // 네 방향 모두 청소할 공간이 없는 경우
        if(map[a][b-1] != 0 && map[a+1][b] != 0 && map[a][b+1] != 0 && map[a-1][b] != 0) {
        	
            // 후방이 벽이라면 동작 멈춤.
            if(d == 0 && map[a+1][b] == 1) break;
            if(d == 1 && map[a][b-1] == 1) break;
            if(d == 2 && map[a-1][b] == 1) break;
            if(d == 3 && map[a][b+1] == 1) break;
            // 후방이 청소한 공간이라면 후진
            if(d == 0) a += 1;
            if(d == 1) b -= 1;
            if(d == 2) a -= 1;
            if(d == 3) b += 1;
            
        } 
        else {
        	// 현재 위치,정면 기준으로 왼쪽만 탐색함!
        	
	        if(d == 0) {
	            if(map[a][b-1] == 0) {
	                b -= 1;
	            }
	            d = 3;
	            continue;
	        } 
	        
	        if(d == 1) {
	            if(map[a-1][b] == 0) {
	                a -= 1;
	            }
	            d = 0;
	            continue;
	        }
	        
	        if(d == 2) {
	            if(map[a][b+1] == 0) {
	                b += 1;
	            }            
	            d = 1;
	            continue;
	        } 
	        if(d == 3) {
	            if(map[a+1][b] == 0){
	                a += 1;
	            }            
	            d = 2;
	            continue;
	        } 
	        
        }
        
        
                
    }
    for(int i = 0; i < N; i++) {
    	for(int j = 0; j < M; j++) {
	    	if(map[i][j] == 2) ret += 1;
    	}
    }
    cout << ret << endl;
    
    return 0;
    
}
