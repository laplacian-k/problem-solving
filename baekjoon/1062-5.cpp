#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// variables
int N, K;
string word[50];
int w[50];

// functions
int teach(int n, int learn)
{
    // 26을 넘어가지 않음.
    if(n == 26) return 0;
    
    // 몇개의 글자를 배웠는지 계산
    int size = 0;
    for(int i = 0; i < 26; i++) {
        if(learn&(1<<i)) size += 1; 
    }
    
    // K개의 글자를 다 배웠다면
    if(size == K) {
        // 단어 집합에서 몇개를 읽을 수 있는지 계산
        int ret = 0;
        for(int i = 0; i < N; i++) {
            if((learn&w[i]) == w[i]) ret += 1;
        }
        return ret;
    }
    
    int ret = 0;
    // n번째 알파벳을 배움.
    ret = max(ret, teach(n+1, learn|(1<<(n+1))));
    // n번째 알파벳을 배우지 않음.
    // antic은 반드시 배움
    if(n+1 != 'a'-'a' && n+1 != 'n'-'a' && n+1 != 't'-'a' && n+1 != 'i'-'a' && n+1 != 'c'-'a')
        ret = max(ret, teach(n+1, learn));
    
    return ret;
}
int main()
{
    // input
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> word[i];
        // pre processing
        for(int j = 0; j < word[i].length(); j++) {
            w[i] |= (1<<(word[i][j]-'a'));
        }
    }
   
    /*
    cout << N << " " << K << endl;
    for(int i = 0; i < N; i++) {
        //cout << word[i] << end;
        cout << w[i] << endl;
    }
    */
    
    
    // algorithm
    // 26개의 알파벳으로 k개의 조합을 만들어야 함.
    // k개의 조합을 다 만들면 N개의 단어 중 몇개를 읽을 수 있는지 계산함
    // O(2^26*50)은 시간초과지만 O(2^21*50)은 시간초과가 나지 않는다!(antic 계산을 제외해야함)
    int ret = 0;    
    ret = teach(-1, 0);
    cout << ret << endl;
    return 0;    
}
