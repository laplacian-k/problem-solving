#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// variables
int N;

// functions
vector<vector<int> > move(vector<vector<int> > b, int dir)
{
    vector<vector<int> > conv(N, vector<int>(N, 0));
    
    // up
    if(dir == 0){
        // each components
        for(int j = 0; j < N; j++) {
            // preprocessing
            vector<int> non_zero_b(N, 0);
            int idx2 = 0;
            for(int i = 0; i < N; i++) {
                if(b[i][j] != 0) {
                    non_zero_b[idx2] = b[i][j];
                    idx2++;
                }
            }
            // init
            vector<bool> canMerge(N, true);
            int idx = 0;
            for(int i = 0; i < N; i++) {
                // if can't merge, skip
                if(!canMerge[i]) continue;
                // if last, add
                if(i == N-1) {
                    conv[idx][j] = non_zero_b[i];
                    break;
                }
                // if same number, add
                if(non_zero_b[i] == non_zero_b[i+1]) {
                    canMerge[i] = canMerge[i+1] = false;
                    conv[idx][j] = non_zero_b[i]*2;
                    idx++;
                }
                else {
                    conv[idx][j] = non_zero_b[i];
                    idx++;
                }
            }
        }   
    }
    // down
    else if(dir == 1){
        // each components
        for(int j = 0; j < N; j++) {
            // preprocessing
            vector<int> non_zero_b(N, 0);
            int idx2 = 0;
            for(int i = N-1; i >= 0; i--) {
                if(b[i][j] != 0) {
                    non_zero_b[idx2] = b[i][j];
                    idx2--;
                }
            }
            // init
            vector<bool> canMerge(N, true);
            int idx = N-1;
            for(int i = N-1; i >= 0; i--) {
                // if can't merge, skip
                if(!canMerge[i]) continue;
                // if last, add
                if(i == 0) {
                    conv[idx][j] = non_zero_b[i];
                    break;
                }
                // if same number, add
                if(non_zero_b[i] == non_zero_b[i-1]) {
                    canMerge[i] = canMerge[i-1] = false;
                    conv[idx][j] = non_zero_b[i]*2;
                    idx--;
                }
                else {
                    conv[idx][j] = non_zero_b[i];
                    idx--;
                }
            }
        }
    }
    // left
    else if(dir == 2){
        // each components
        for(int i = 0; i < N; i++) {
            // preprocessing
            vector<int> non_zero_b(N, 0);
            int idx2 = 0;
            for(int j = 0; j < N; j++) {
                if(b[i][j] != 0) {
                    non_zero_b[idx2] = b[i][j];
                    idx2++;
                }
            }
            // init
            vector<bool> canMerge(N, true);
            int idx = 0;
            for(int j = 0; j < N; j++) {
                // if can't merge, skip
                if(!canMerge[j]) continue;
                // if last, add
                if(j == N-1) {
                    conv[i][idx] = non_zero_b[j];
                    break;
                }
                // if same number, add
                if(non_zero_b[j] == non_zero_b[j+1]) {
                    canMerge[j] = canMerge[j+1] = false;
                    conv[i][idx] = non_zero_b[j]*2;
                    idx++;
                }
                else {
                    conv[i][idx] = non_zero_b[j];
                    idx++;
                }
            }
        }    
    }
    // right
    else if(dir == 3){
        // each components
        for(int i = 0; i < N; i++) {
            // preprocessing
            vector<int> non_zero_b(N, 0);
            int idx2 = N-1;
            for(int j = N-1; j >= 0; j--) {
                if(b[i][j] != 0) {
                    non_zero_b[idx2] = b[i][j];
                    idx2--;
                }
            }
            // init
            vector<bool> canMerge(N, true);
            int idx = N-1;
            for(int j = N-1; j >= 0; j--) {
                // if can't merge, skip
                if(!canMerge[j]) continue;
                // if last, add
                if(j == 0) {
                    conv[i][idx] = non_zero_b[j];
                    break;
                }
                // if same number, add
                if(non_zero_b[j] == non_zero_b[j-1]) {
                    canMerge[j] = canMerge[j-1] = false;
                    conv[i][idx] = non_zero_b[j]*2;
                    idx--;
                }
                else {
                    conv[i][idx] = non_zero_b[j];
                    idx--;
                }
            }
        }
    }  
        
    return conv;
}

int go(vector<vector<int> >& b, int d)
{
    /*
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    */
    if(d == 5) {
        // search the max value
        int ans = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                ans = max(ans, b[i][j]);
            }
        }
        return ans;
    }
    
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        vector<vector<int > > conv = move(b, i);
        ret = max(ret, go(conv, d+1));
    }
    
    return ret;
}

int main()
{
    // input
    cin >> N;
    vector<vector<int> > board(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            //cout << board[i][j] << " ";
        }
        //cout << "\n";
    }
    
    // algorithm
    int ret = 0;
    ret = go(board, 0);
    cout << ret << "\n";
    
    return 0;
}
