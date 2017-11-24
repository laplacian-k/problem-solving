#include <iostream>
#include <string>
using namespace std;

// variables
int R, C;
string cave[100];
int N;
int h[100];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0 , 0,-1, 1};
int cnt;
bool visit[100][100];
int a[100][100];

// functions
void destroy(int i)
{
    // 짝수면 왼->오, 홀수면 오->왼    
    int high = R-h[i];
    // 홀수
    if(i&1){
        for(int k = C-1; k >= 0; k--) {
            if(cave[high][k] == 'x'){
                //cout << "미네랄발견!" << endl;
                cave[high][k] = '.';
                break;
            }
        }
    }
    else {
        for(int k = 0; k < C; k++) {
            if(cave[high][k] == 'x'){
                //cout << "미네랄발견!" << endl;
                cave[high][k] = '.';
                break;
            }
        }        
    }
    
    return;
}

void dfs(int y, int x)
{
    // 방문표시
    visit[y][x] = true;
    a[y][x] = cnt;
    
    for(int i = 0; i < 4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(!((0 <= ny && ny < R) && (0 <= nx && nx < C))) continue;
        if(cave[ny][nx] == '.' || visit[ny][nx]) continue;        
        dfs(ny, nx);
    }
}

void update()
{
    // 떨어질 클러스터의 번호를 찾는다.
    // 클러스터번호의 최대 y값이 7이 아니라면 공중에 떠있는 클러스터
    //int check1 = pow(2,cnt)-1;
    int check = 0;
    for(int x = 0; x < C; x++) {
        if(a[R-1][x] == 0) continue;
        // 바닥에 닿아있는 클러스터 번호의 집합을 만든다.
        check |= (1<<(a[R-1][x]-1));
    }
    
    int cluster = -1;
    for(int i = 0; i < cnt; i++) {
        // 1~cnt까지의 집합 중 바닥에 닿아있지 않은 클러스터를 발견하면 탐색 종료.
        if(!(check&(1<<i))) {
            cluster = i+1;
            break;
        }
    }    
    //cout << cluster << endl;
    // 전부 닿아있으면 종료
    if(cluster == -1) return;
    else {
        // 찾은 클러스터 번호 기준, 아래로 움직여봄.
        // 바닥에 존재하는 미네랄 중 하나라도 땅에 닿거나 다른 클러스터에 닿는다면 이동 종료.
    }
    
    return;    
}

int main()
{
    // input
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        cin >> cave[i];
    }
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }
    /*
    cout << R << " " << C << endl;
    for(int i = 0; i < R; i++) {
        cout << cave[i] << endl;
    }
    cout << N << endl;
    for(int i = 0; i < N; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
    */
    
    // algorithm
    // 동굴을 놓고 소유권을 주장함
    // 던진 막대기가 미네랄을 파괴할 수 있음.
    // 각 칸은 비어있거나 미네랄이 있음.
    // 창영이는 동굴 왼쪽, 상근이는 동굴 오른쪽에 서있음.
    // 막대를 던질 높이를 정하면 막대는 땅과 수평으로 날라감 (턴제 게임임. 왼쪽에서 오른쪽부터 던짐)
    // 클러스터의 정의? 인접하면 됨. 중력에 의해서 밑으로 떨어짐.
    // 클러스터는 다른 클러스터나 땅을 만나기 전까지 게속해서 떨어진다(클러스터를 인식하고 그 클러스터의 밑바닥에 무언가 닿아야함)
    // 공중에 떠 있는 미네랄 클러스터는 없으며, 두 개 또는 그 이상의 클러스터가 동시에 떨어지는 경우도 없다.
    
    for(int i = 0; i < N; i++) {
        // 짝수면 왼->오, 홀수면 오->왼        
        // 미네랄 파괴
        destroy(i);
        // 클러스터 검증
        // init
        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                visit[j][k] = false;
                a[j][k] = 0;
            }
        }
        cnt = 0;
        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                if(cave[j][k] == '.' || visit[j][k]) continue;
                cnt++;
                dfs(j, k);
            }
        }
        
        cout << "cnt : " << cnt << endl;
        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                cout << a[j][k];
            }
            cout << endl;
        }
        cout << endl;
        
        // 동굴업데이트
        // 클러스터가 1개일 경우에도 아래로 떨어질 수 있다.
        update();
        
    }
    
    // 변경된 동굴의 모습이 출력됨.
    for(int i = 0; i < R; i++) {
        cout << cave[i] << endl;
    }
    
    return 0;
}
