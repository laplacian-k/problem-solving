#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

// variables
int N, M;
int A[50][50];
int B[50][50];
bool visit[50][50];
int dist[50][50];
const int inf = 1000000000;

// functions
/*
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
*/

int BFS(int y, int x)
{    
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            visit[i][j] = false;
            //dist[i][j] = inf;
        }
    }
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    
    // 만약 A를 B로 바꿀 수 없다면 -1을 출력한다.
    int ret = -1;
    
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        int d = q.front().third;
        
        // visited 체크할 필요 없음.
        
        // 큐에서 제거
        q.pop();        
        // 행렬 변경
        update(A);
        // 큐에 거리를 담아서 가져가자.
        
        for(int i = a; i < N; i++) {
            for(int j = b; j < M; j++) {
                if(i == a && j == b) continue;
                q.push(make_pair(i, j));
            }
        }
        
        // 두 행렬이 같아지면 종료
        bool isEqual = true;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(A[i][j] != B[i][j]) {
                    isEqual = false;
                    break;
                }
            }
        }
        if(isEqual) {
            ret = d;
            break;
        }
    }    
    
    return ret;
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
    // 두 행렬이 같아지는 최소 연산의 수를 구하시오.
    
    for(int i = 2; i < N; i++) {
        for(int j = 2; j < M; j++) {
            ret = min(ret, BFS(y, x));
        }
    }

    cout << ret << endl;
    
    return 0;
}
