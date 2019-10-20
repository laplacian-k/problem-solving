#include <iostream>
using namespace std;

// variables
int N, M, K;
int map[20][20];
int comm[1000];
struct data {
    int up;
    int down;
    int left;
    int right;
    int face;
    int tail;
};

// functions
void moveDice(data& dice, int dir)
{
    data prev = dice;
    // 동
    if(dir == 1) {
        dice.up = prev.left;
        dice.down = prev.right;
        dice.left = prev.down;
        dice.right = prev.up;
        dice.face = prev.face;
        dice.tail = prev.tail;          
    }
    // 서
    else if(dir == 2) {
        dice.up = prev.right;
        dice.down = prev.left;
        dice.left = prev.up;
        dice.right = prev.down;
        dice.face = prev.face;
        dice.tail = prev.tail;
    }
    // 남
    else if(dir == 4) {
        dice.up = prev.tail;
        dice.down = prev.face;
        dice.left = prev.left;
        dice.right = prev.right;
        dice.face = prev.up;
        dice.tail = prev.down;
    }
    // 북
    else if(dir == 3) {
        dice.up = prev.face;
        dice.down = prev.tail;
        dice.left = prev.left;
        dice.right = prev.right;
        dice.face = prev.down;
        dice.tail = prev.up;
    }
}

int main()
{
    // init
    data dice = {0, 0, 0, 0, 0, 0};
    // input
    int x, y;
    cin >> N >> M;
    cin >> x >> y;
    cin >> K;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < K; i++){
        cin >> comm[i];
    }
    

    // algorithm
    for(int i = 0; i < K; i++) {
        int next_x = x;
        int next_y = y;
        // 지도 이동(x, y로 컨트롤)
        if(comm[i] == 1) {
            next_y = y+1;
        }
        else if(comm[i] == 2) {
            next_y = y-1;
        }
        else if(comm[i] == 4) {
            next_x = x+1;
        }
        else if(comm[i] == 3) {
            next_x = x-1;
        }
        // validation check
        if( !((0<= next_x && next_x < N) && (0 <= next_y && next_y < M)) )
            continue;        
        x = next_x;
        y = next_y;
        // 주사위 이동
        moveDice(dice, comm[i]);
        
        // 지도가 0이면 주사위 바닥면 수가 복사됨.
        if(map[x][y] == 0) {
            map[x][y] = dice.down;
        }
        // 지도가 0이 아니면 지도의 수가 주사위 바닥면으로 복사되고 지도의 수는 0이 됨.
        else {
            dice.down = map[x][y];
            map[x][y] = 0;
        }   
        // 주사위 윗면의 수를 출력
        cout << dice.up << endl;
    }
}
