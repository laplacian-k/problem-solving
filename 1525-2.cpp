#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

// variables
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int main()
{
    // input
    int start = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            // 숫자로 받음.
            int temp;
            cin >> temp;
            if(temp == 0) temp = 9;
            start = start*10 + temp;
        }
    }
    
    // algorithm    
    queue<int> q;
    map<int, int> dist;
    
    // 초기화
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        string puzzle = to_string(cur);
        q.pop();
        
        // 0(9)의 위치를 찾음 
        int z = puzzle.find('9');
        int y = z/3;
        int x = z%3;
        
        // 해당 위치를 기준으로 상하좌우를 탐색한다.
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
            if(dist.count(next) != 0) continue;  
            
            q.push(next);
            dist[next] = dist[cur] + 1;
        }      

    }
    
    // 이동이 불가능한 경우 -1을 출력한다.
    if(dist.count(123456789) == 0) {
        cout << -1 << endl;
    }
    else {
        cout << dist[123456789] << endl;   
    }
    
    return 0;
}
