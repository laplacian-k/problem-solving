#include <iostream>
#include <vector>
using namespace std;

// variables
const int inf = 1000000000;

// functions
int dfs(vector<vector<int> >& p, int d)
{
    // 정리된 상태를 찾았으면 return
    bool fin = true;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(p[i][j] != (i*3)+(j+1)){
                fin = false;
            }
        }
    }
    if(fin) return d;
    
    for(int i = 0; i < 4; i++) {
        
    }
    return 0;
}

int main()
{
    // init
    vector<vector<int> > a(3, vector<int>(3, 0));
    // input
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    
    // algorithm
    // 이동이 불가능한 경우 -1을 출력한다.
    int ret = dfs(a, 0);
    cout << ret << endl;
    return 0;
}
