#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>    // for make_tuple

using namespace std;

// variables
int A, B, C;

int main()
{
    // input
    cin >> A >> B >> C;    
    
    // algorithm
    const int bowl[3] = {A, B, C};
    bool visit[201][201][201];
    for(int i = 0; i < 201; i ++) {
        for(int j = 0; j < 201; j++) {
            for(int k = 0; k < 201; k++) {
                visit[i][j][k] == false;
            }
        }
    }    
    queue<tuple<int, int, int> > q;
    // 초기화
    q.push(make_tuple(0, 0, C));
    visit[0][0][C] = true;    
    
    // 정답
    vector<int> ans;
    
    while(!q.empty()) {
        int a, b, c;
        tie(a, b, c) = q.front();
        q.pop();
        int cur[3] = {a, b, c};
        //cout << a << ", " << b << ", " << c << endl;
        // 첫번째 물통이 비어있다면 세번째 물통의 값을 저장한다.
        if(a == 0) ans.push_back(c);
        
        // 한 물통이 비거나, 다른 한 물통이 가득 찰 때까지 물을 부을 수 있다.                
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                // cur값으로 초기화
                int next[3] = {a, b, c};
                // 같은 물통 skip
                if(i == j) continue;
                
                // i->j로 물을 옮김
                int k = cur[i] + cur[j];
                if(k <= bowl[j]) {
                    next[i] = 0;
                    next[j] = k;
                }
                else {
                    next[i] = k-bowl[j];
                    next[j] = bowl[j];
                }
                int na = next[0];
                int nb = next[1];
                int nc = next[2];
                
                if(visit[na][nb][nc]) continue;
                visit[na][nb][nc] = true;
                q.push(make_tuple(na, nb, nc));                
            }
        }
    }   
    
    // 각 용량은 오름차순으로 정렬한다
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
