#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// variables
int R, C;
string board[20];
bool visit[26];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};


// functions
int go(int y, int x)
{
    int ret = 0;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 범위를 벗어나면 skip
        if(!((0 <= ny && ny < R) && (0 <= nx && nx < C))) continue;
        // 이미 지나간 알파벳이면 방문 불가능
        if(visit[board[ny][nx]-'A']) continue;
        
        visit[board[ny][nx]-'A'] = true;
        ret = max(ret, go(ny, nx)+1);
        visit[board[ny][nx]-'A'] = false;        
    }
    
    return ret;
}
int main()
{
    // init
    for(int i = 0; i < 26; i++) {
        visit[i] = false;
    }
    
    // input
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        cin >> board[i];
    }
    /*
    cout << R << ", " << C << '\n';
    for(int i = 0; i < R; i++) {
        cout << board[i] << '\n';
    }
    */
    
    // algorithm
    int ret = 0;
    // 좌측상단 방문
    //cout << board[0][0]-'A' << '\n';
    visit[board[0][0]-'A'] = true;
    ret = go(0, 0)+1;
    cout << ret << '\n';
    return 0;
}
