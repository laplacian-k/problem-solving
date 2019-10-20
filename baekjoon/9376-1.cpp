#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

// variables
int T;
int h, w;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

// functions
vector<vector<int> > bfs(vector<string>& j, int a, int b)
{
    int n = j.size();
    int m = j[0].size();
    
    vector<vector<int> > d(n, vector<int>(m, -1));    // dist 초기화
    deque<pair<int, int> > dq;
    //dq.push_front(make_pair(a, b));
    dq.push_back(make_pair(a, b));
    d[a][b] = 0;
    
    while(!dq.empty()) {
        // 방문
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        
        for(int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            
            // 입력으로 들어온 배열 a의 범위를 벗어나면 skip
            if(!((0 <= ny && ny < n) && (0 <= nx && nx < m))) continue;
            // 이미 방문했다면 skip
            if(d[ny][nx] != -1) continue;
            // 벽이라면 skip
            if(j[ny][nx] == '*') continue;
            // 문을 열어야 된다면
            if(j[ny][nx] == '#') {
                d[ny][nx] = d[y][x] + 1;
                dq.push_back(make_pair(ny, nx));    // 뒤쪽에 push
            }
            // 문을 열지 않아도 되는 장소라면(빈칸 '.', 죄수'$')
            else {
                d[ny][nx] = d[y][x];
                dq.push_front(make_pair(ny, nx));    // 앞쪽에 push
            }
        }
    }
    
    return d;    // dist를 리턴
}

int main()
{
    // input1
    cin >> T;
    //cout << T << endl;
    for(int test_case = 0; test_case < T; test_case++) {
        // input2
        cin >> h >> w;
        
        // h+2, w+2에 대해 빈 공간을 넣어준다.
        string s = "";
        for(int i = 0; i < w+2; i++)
            s += ".";
        
        vector<string> jail(h+2, s);
        
        for(int i = 1; i <= h; i++) {
            string s = "";
            cin >> s;
            jail[i] = "." + s + ".";
        }
        // output
        /*
        cout << h << " " << w << endl;
        for(int i = 0; i < h+2; i++) {
            cout << jail[i] << endl;
        }
        */
        
        // algorithm
        // 두명의 죄수가 만나는 최소 거리의 위치를 구함
        // 감옥 밖에서 그 위치까지 가는 최소거리를 구함.(감옥 밖은 전부 빈방으로 보면 됨)
        // BFS의 가중치는 여는 문의 개수
        
        // (0, 0)에서 문까지 가는 bfs를 구함
        vector<vector<int> > d0 = bfs(jail, 0, 0);
        
        // 죄수의 위치를 찾음
        vector<pair<int, int> > p;
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <=w; j++) {
                if(jail[i][j] == '$') p.push_back(make_pair(i, j));
            }
        }
        
        // 죄수의 위치부터 bfs
        vector<vector<int> > d1 = bfs(jail, p[0].first, p[0].second);
        vector<vector<int> > d2 = bfs(jail, p[1].first, p[1].second);
        
        int ret = h*w;   // 열어야하는 문의 최대값
        for(int i = 0; i < h+2; i++) {
            for(int j = 0; j < w+2; j++) {
                // 벽이라면 skip
                if(jail[i][j] == '*') continue;
                int d = d0[i][j] + d1[i][j] + d2[i][j];
                if(jail[i][j] == '#') d -= 2;    // 문에서 만났다면 열어야하는 문의 수는 2개가 중복된다.
                // 빈칸에서 만난걸 d로 계산하게되면 본래의 d보다 큰 수(이상)가 나올 수 밖에 없다.
                // 이 d는 정답이 될 수 없으므로 위 -2와 같은 처리를 해줄 필요는 없다.
                ret = min(ret, d);
            }
        }
        cout << ret << endl;
    }
    
    return 0;
}
