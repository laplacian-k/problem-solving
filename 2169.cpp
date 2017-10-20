#include <iostream>
using namespace std;

// variables
int N, M;
int v[1001][1001];

int main()
{
    // input
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> v[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }    
    
    // algorithm
    int ret = 0;
    cout << ret << endl;
}
