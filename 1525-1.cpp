#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// variables
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
map<int, bool> visit;
const int inf = 1000000000;    // max = 9!


// functions
int dfs(int cur, int d)
{
    if(cur == 123456789) return d;
    
    string puzzle = to_string(cur);
    // 0의 위치를 찾음.
    int z = puzzle.find('9');
    int y = z/3;
    int x = z%3;
    
    int ret = inf;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        // 벗어나면 skip
        if(!((0 <= ny && ny < 3) && (0<= nx && nx < 3))) continue;
        
        // 다음 숫자를 만듦.
        string next_puzzle = puzzle;
        swap(next_puzzle[z], next_puzzle[3*ny + nx]);
            
        int next = stoi(next_puzzle);            
        
        // 갔던 곳이라면 가지 않는다.
        if(visit.count(next) != 0 && visit[next]) continue;
        
        visit[next] = true;
        ret = min(ret, dfs(next, d+1));
    }
    
    return ret;
}

int main()
{
    // input
    int start = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int temp;
            cin >> temp;
            if(temp == 0) temp = 9;
            start = start*10 + temp;
        }
    }
    
    // algorithm
    // 이동이 불가능한 경우 -1을 출력한다.
    visit[start] = true;
    int ret = dfs(start, 0);
    cout << ret << endl;
    return 0;
}
