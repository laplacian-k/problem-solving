#include <iostream>
#include <vector>
using namespace std;

// variables
int N;
bool visit[9];

// functions
void go(vector<int>& p)
{
    // cout << cur << ", " << d << endl;
    if(p.size() == N) {
        for(int i = 0; i < p.size(); i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int next = 1; next <= N; next++) {
        if(visit[next]) continue;
        visit[next] = true;
        p.push_back(next);
        go(p);
        p.pop_back();
        visit[next] = false;
    }
}

int main()
{
    // init
    for(int i = 0; i < 9; i++) {
        visit[i] = false;
    }
    // input
    cin >> N;
    
    vector<int> p;
    
    // algorithm
    for(int i = 1; i <= N; i++) {
        if(visit[i]) continue;
        visit[i] = true;
        //cout << i << "삽입!" <<endl;
        p.push_back(i);
        go(p);
        visit[i] = false;
        p.pop_back();
    }

    
    return 0;
}
