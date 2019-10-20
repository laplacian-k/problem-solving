#include <iostream>
#include <string>
using namespace std;

// variables
int N, M;
int A[50][50];
int B[50][50];

// functions
// i, j기준 행렬A를 업데이트하는 함수
void update(int i, int j)
{
    for(int y = i; y < i+3; y++) {
        for(int x = j; x < j+3; x++) {
            // XOR 연산 : 0->1, 1->0
            A[y][x] = (A[y][x]^1);
        }
    }
}
int main()
{
    // input
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++) {
            A[i][j] = s[j]-'0';
        }
        
    }
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++) {
            B[i][j] = s[j]-'0';
        }
        
    }
    // output
    /*
    cout << N << " "<< M << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << A[i][j];
        }
        cout << endl;
        
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << B[i][j];
        }
        cout << endl;
    }
    */
    
    // algorithm
    // 행렬을 변환하는 연산은 어떤 3*3크기의 부분 행렬에 있는 모든 원소를 뒤집는 것
    // A를 B로 바꿀 수 없다면 -1 출력
    int ret = -1;
    int cnt = 0;
    for(int i = 0; i < N-2; i++) {
        for(int j = 0; j < M-2; j++) {
            if(A[i][j] != B[i][j]){
                update(i, j);
                cnt++;
            }
        }
    }
    
    bool canMake = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] != B[i][j]) {
                canMake = false;
                break;
            }                
        }
        if(!canMake) break;
    }
    if(canMake) ret = cnt;
    cout << ret << endl;
    
    return 0;
}
