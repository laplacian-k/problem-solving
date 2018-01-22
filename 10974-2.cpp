#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// variables
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    // input
    cin >> N;
    
    vector<int> p;
    
    // algorithm
    for(int i = 1; i <= N; i++) {
        p.push_back(i);
    }
    for(int i = 0; i < N; i++) {
        cout << p[i] << ' ';
    } 
    cout << endl;
    
    
    while(next_permutation(p.begin(), p.end())) {
        for(int i = 0; i < N; i++) {
            cout << p[i] << ' ';
        }
        cout << endl;
    }
    
    
    return 0;
}
