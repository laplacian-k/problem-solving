#include <iostream>
#include <string>
using namespace std;

// variables
int N, M;
int A[50][50];
int B[50][50];
bool visit[50][50];

// functions
int matrix(int y, int x, int d)
{
    // 행렬A가 행렬B가 됐다면 탐색종료
    isEqual = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] != B[i][j]) {
                isEqual = false;
                break;
            }
        }
    }
    if(isEqual) return d;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // 우 하단 방향만 가능
            visit[i][j] = true;
            matrix(d+1)
            visit[i][j] = false;
        }
    }
}
int main()
{
    // init
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visit[i][j] = false;
        }
    }
    // input
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++) {
            A[i][j] = s[j]-'0';
        }
    }
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++) {
            B[i][j] = s[j]-'0';
        }
    }    
    
    // algorithm
    int ret = 0;
    // 최소 연산의 수를 구하시오 -> BFS?
    ret = matrix();
    cout << ret << endl;
    
    return 0;
}
