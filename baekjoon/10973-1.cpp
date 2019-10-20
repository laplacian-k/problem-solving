#include <iostream>
#include <vector>
#include <algorithm>    // for next_permutation
using namespace std;

// variables
int N;

int main()
{
    // input
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // algorithm
    if(prev_permutation(a.begin(), a.end())) {
        for(int i = 0; i < N; i++) {
            cout << a[i] << ' ';    
        }        
    }
    else {
        cout << -1 << endl;
    }
    cout << endl;
    
    return 0;
}
