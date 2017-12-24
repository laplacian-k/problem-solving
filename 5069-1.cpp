#include <iostream>
using namespace std;

// variables
int n;
int d[15][30][30];    // 음수 방지
const int dy[] = {-1, -1, 0, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 0, -1};

int main()
{
    int T;
    cin >> T;
    
    // algorithm
    // d[k][y][x] = (0, 0)에서 출발해서 k번만에 y,x에 도착하는 경우의 수
    d[0][14][14] = 1;
    for(int k = 1; k <= 14; k++) {
        for(int i = 0; i < 30; i++) {
            for(int j = 0; j < 30; j++) {
                for(int l = 0; l < 6; l++) {
                    int y = i + dy[l];
                    int x = j + dx[l];
                    if(!((0 <= y && y < 30) && (0 <= x && x < 30))) continue;
                    d[k][i][j] += d[k-1][y][x];
                }
            }
        }
    }
    while(T--) {
        // input
        cin >> n;
        cout << d[n][14][14] << endl;
        
    }
    
    return 0;
}
