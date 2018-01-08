#define N 4

 

typedef struct {

           int strike;

           int ball;

} Result;

 

// API

extern Result query(int guess[]);

 

void doUserImplementation(int guess[]) {
    bool canUse[10];
    int base[4] = {1000, 100, 10, 1};
    int s = -1;
    int b = -1;
    
    // init
    for(int i = 0; i < 10; i++) {
        canUse[i] = true;
    }
    guess = { 0, 1, 2, 3};
    int n = 123;
    while(s != 4) {
        Result ret = query(guess);
        s = ret.strike;
        b = ret.ball;
        
        // if(s == 4) break;
        
        // guess prediction
        n += 1
        for(int i = 0; i < 4; i ++) {
        	guess[i] = n/base[i];
            n -= guess[i];
        }
    }
   
}
