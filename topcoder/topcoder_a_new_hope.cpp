#include <iostream>
#include <vector>
using namespace std;

class ANewHope {
public:
	int count(vector<int> firstWeek, vector<int> lastWeek, int D);   
};
    
int ANewHope::count(vector<int> firstWeek, vector<int> lastWeek, int D) {
    
    int N = firstWeek.size();
    // validation
    bool isEqual = true;
    for(int i = 0; i < N; i++) {
        if(firstWeek[i] != lastWeek[i]) {
            isEqual = false;
            break;
        }
    }
    
    if(isEqual) return 1;            
    
    // init last week index
    vector<int> idxs(2501, -1);    
    for(int i = 0; i < N; i++) {
        idxs[lastWeek[i]] = i;
    }
    
    int ret = 2;
    
    while(1) {
        
        bool canMake = true;       
        vector<int> mid(N);
        
        for(int i = 0; i < N; i++) {
            if(i+D < N) {
                mid[i+D] = firstWeek[i];
                continue;
            }            
            
            if((i+D)%N > idxs[firstWeek[i]]) {
                canMake = false;
            }
            
            mid[(i+D)%N] = firstWeek[i];
        }
        
        if(canMake) break;
        
        firstWeek = mid;
        ret += 1;
    }
    
    return ret;
}
