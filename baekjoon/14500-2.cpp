#include <iostream>
#include <algorithm>
using namespace std;

// variables
int N, M;
int a[501][501];
const int tet[19][4][2] = {
    { {0, 0}, {0, 1}, {0, 2}, {0, 3}},
    { {0, 0}, {1, 0}, {2, 0}, {3, 0}},
    
    { {0, 0}, {0, 1}, {1, 0}, {1, 1}},
    
    { {0, 0}, {1, 0}, {2, 0}, {2, 1}},
    { {0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    { {0, 0}, {0, 1}, {1, 1}, {2, 1}},
    { {0, 0}, {1, 0}, {0, 1}, {0, 2}},
    
    { {0, 0}, {1, 0}, {2, 0}, {2, -1}},
    { {0, 0}, {0, 1}, {0, 2}, {1, 2}},
    { {0, 0}, {1, 0}, {2, 0}, {0, 1}},
    { {0, 0}, {1, 0}, {1, 1}, {1, 2}},    
    
    { {0, 0}, {1, 0}, {1, 1}, {2, 1}},
    { {0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    
    { {0, 0}, {1, 0}, {1, -1}, {2, -1}},
    { {0, 0}, {0, 1}, {1, 1}, {1, 2}},
    
    { {0, 0}, {0, 1}, {0, 2}, {1, 1}},
    { {0, 0}, {1, 0}, {1, 1}, {2, 0}},
    { {0, 0}, {0, 1}, {0, 2}, {-1, 1}},
    { {0, 0}, {1, 0}, {1, -1}, {2, 0}}
};

int main()
{
    // input
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    
    // algorithm
    int ret = 0;
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            
            for(int m = 0; m < 19; m++) {
                
                int sum = 0;
                for(int n = 0; n < 4; n++) {
                    int ny = y + tet[m][n][0];
                    int nx = x + tet[m][n][1];
                    if(!((0 <= ny && ny < N) && (0 <= nx && nx < M))) break;
                    
                    sum += a[ny][nx];
                }
                
                ret = max(ret, sum);                
            }
        }
    }
    
    cout << ret << "\n";
    return 0;
}