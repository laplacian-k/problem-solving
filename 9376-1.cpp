#include <iostream>
#include <string>
using namespace std;

// variables
int T;
int h, w;
string jail[100];

int main()
{
    // input1
    cin >> T;
    //cout << T << endl;
    for(int test_case = 0; test_case < T; test_case++) {
        // input2
        cin >> h >> w;
        for(int i = 0; i < h; i++) {
            cin >> jail[i];
        }
        // output
        /*
        cout << h << " " << w << endl;
        for(int i = 0; i < h; i++) {
            cout << jail[i] << endl;
        }
        */
        
        // algorithm
        // 두명의 죄수가 만나는 최소 거리의 위치를 구함
        // 감옥 밖에서 그 위치까지 가는 최소거리를 구함.(감옥 밖은 전부 빈방으로 보면 됨)
        // BFS의 가중치는 여는 문의 개수
        // 안 여는 위치부터 먼저 가본다!
    }
    
    return 0;
}
