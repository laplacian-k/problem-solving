#include <iostream>
#include <vector>
using namespace std;

class ANDEquation {
public:
	int restoreY(vector<int> A);   
};
    
int ANDEquation::restoreY(vector<int> A) {
    
    for(int i = 0; i < A.size(); i++) {
        int left = ~(0);
        for(int j = 0; j < A.size(); j++) {
            if(i == j) continue;
            left &= A[j];
        }
        if(left == A[i]) return A[i];            
    }
    return -1;
}
