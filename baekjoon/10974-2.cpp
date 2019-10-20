#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// variables
int N;

int main()
{
    // input
    cin >> N;
    
    vector<int> p(N);
    
    // algorithm
    for(int i = 0; i < N; i++) {
        p[i] = i+1;
        cout << p[i] << ' ';
    }
    cout << '\n';
    
    
    while(next_permutation(p.begin(), p.end())) {
        for(int i = 0; i < N; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
    
    
    return 0;
}
