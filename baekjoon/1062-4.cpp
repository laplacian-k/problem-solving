#include <iostream>
#include <bitset>
using namespace std;

// variables
int N, K;
int w[51];

// functions
int solve(int index, int learn, int cnt)
{
    // cnt가 K를 초과하는 가지는 만들지 않음.
    if(cnt > K) return 0;
    // 알파벳 26개의 조합을 모두 만들었다면 정답 판단
    if(index == 26) {
        int ret = 0;
        for(int i = 1; i <= N; i++) {
            int set = (learn&w[i]);
            if(set == w[i]) ret++;
        }
        return ret;
    }
    int ret = 0;
    // 이번 알파벳을 선택
    ret = max(ret, solve(index+1, learn|(1<<index), cnt+1));
    // 이번 알파벳을 선택 x
    if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a')
        ret = max(ret, solve(index+1, learn, cnt));
    
    return ret;
}
int main()
{
    // input
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        string word;
        cin >> word;
        int s = 0;
        for(int j = 0; j < word.length(); j++) {
            s |= (1<<word[j]-'a');
        }
        w[i] = s;
    }
    
    // algorithm
    // antic는 무조건 배워야 함.
    int ret = 0;
    
    if(K < 5) ret = 0;
    else if(K == 26) ret = N;
    else ret = solve(0, 0, 0);
    
    cout << ret << endl;
        
}
