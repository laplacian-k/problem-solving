#include <iostream>
using namespace std;

// variables
int N;
int subway[50000];
int K;

// functions

int main()
{
    // input
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >>subway[i];
    }
    cin >> K;
    
    // algorithm
    int ret = 0;
    ret = go();
    cout << ret << endl;
    
}
