#include <iostream>
#include <string>
using namespace std;

// variables
int R, C;
string cave[100];
int N;
int h[100];

// functions
void destroy(int i)
{
    // 짝수면 왼->오, 홀수면 오->왼        
    
    int high = h[i]-1;
    // 홀수
    if(i&1){
        for(int k = C-1; k >= 0; k--) {
            if(cave[high][k] == 'x'){
                cave[high][k] = '.';
                break;
            }
        }
    }
    else {
        for(int k = 0; k < C; k++) {
            if(cave[high][k] == 'x'){
                cave[high][k] = '.';
                break;
            }
        }        
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
    
    // algorithm
    // 동굴을 놓고 소유권을 주장함
    // 던진 막대기가 미네랄을 파괴할 수 있음.
    // 각 칸은 비어있거나 미네랄이 있음.
    // 창영이는 동굴 왼쪽, 상근이는 동굴 오른쪽에 서있음.
    // 막대를 던질 높이를 정하면 막대는 땅과 수평으로 날라감 (턴제 게임임. 왼쪽에서 오른쪽부터 던짐)
    // 클러스터의 정의? 인접하면 됨. 중력에 의해서 밑으로 떨어짐.
    // 클러스터는 다른 클러스터나 땅을 만나기 전까지 게속해서 떨어진다(클러스터를 인식하고 그 클러스터의 밑바닥에 무언가 닿아야함)
    
    for(int i = 0; i < N; i++) {
        // 짝수면 왼->오, 홀수면 오->왼        
        // 미네랄 파괴
        destroy(i);
        // 클러스터 검증
        
        // 동굴업데이트
    }
    
    // 변경된 동굴의 모습이 출력됨.
    for(int i = 0; i < R; i++) {
        cout << cave[i] << endl;
    }
    
    return 0;
}
