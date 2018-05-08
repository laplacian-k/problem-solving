#include <iostream>
#include <string>
using namespace std;

class AB {
public:
	string createString(int, int);
};

string AB::createString(int N, int K) {
    string ret = "";
    if(K == 0) {
        ret = "B";
        ret.append(N-1, 'A');
    	return ret;
    }
    int b_cnt = (N/2);
    int a_cnt = N-b_cnt;
    int max_pair = a_cnt*b_cnt;
    if(max_pair < K) return "";
    else if(max_pair == K) {
    	ret.append(a_cnt, 'A');
        ret.append(b_cnt, 'B');
        return ret;
    }
    else {
        for(int i = 1; i <= N-1; i++) {
            if(K%i != 0) continue;
        	int base = K/i;
            int len = i+base;
            if(len > N) continue;
            
            ret.append(N-len, 'B');
            ret.append(i, 'A');
            ret.append(base, 'B');
            return ret;            
        }
    }
        
	return "";
}
