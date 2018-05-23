#include <iostream>
#include <vector>
using namespace std;

class ANewHope {
public:
	int count(vector<int> firstWeek, vector<int> lastWeek, int D);   
};
    
int ANewHope::count(vector<int> firstWeek, vector<int> lastWeek, int D) {
    int N = firstWeek.size();
    vector<int> idxs(N, -1);
    
    for(int i = 0; i < N; i++) {
        idxs[lastWeek[i]] = i;
    }
    
    int ret = 0;
    vecter<int> conv = firstWeek;
    while(1) {
        for(int i = 0; i < N; i++) {
            conv[(i+D)%N] = firstWeek[i];
        }
        
        firstWeek = conv;
        
        bool canMake = true;
        for(int i = 0; i < N; i++) {
            if(i > idxs[conv[i]]) {
                canMake = false;
                break;
            }
        }
        
        if(canMake) break;
        
        ret += 1;
    }
    
    return ret;
}
