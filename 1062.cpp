#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// variables
int N, K;
string word[51];

// functions
// learn집합으로 읽을 수 있는 단어의 최대 수
int solve(int learn, int cnt)
{
    // 배운 알파벳 수가 K를 넘어가면 안됌.
    if(cnt > K) {
        int ret = 0;
        for(int i = 0; i < N; i++) {
            bool canMake = true;
            for(int j = 0; j < word[i].length(); j++) {
                if( (learn & (1<<(word[i][j]-'a'))) != 1 ) {
                    canMake = false;
                    break;
                }
            }
            if(canMake)
                cnt++;
        }
        return cnt;
    }
    
    int ret = 0;
    // 배우는 알파벳의 조합을 만듦.
    for(int i = 0; i < 26; i++) {
        // 이미 배웠으면 skip
        if((learn & (1<<i)) == 1) continue;
        ret = max(ret, solve((learn+(1<<i)), cnt+1));
    }
    
    return ret;
}

int main()
{
    // input
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        // 길이가 8이상 15이하인 단어가 들어옴.
        cin >> word[i];
    }
    
    
    // algorithm
    // antatica -> a, n, t, i, c 5글자는 반드시 알아야 함.
    int learn = (1<<0) + (1<<2) + (1<<11) + (1<<14) + (1<<20);
    // 5 + antic 이외의 글자 집합의 개수 > K라면 그 단어는 배울 수 없음.
    
    // 2차원 배열로 만들어놓고 알파벳 별로 필요한 개수를 카운트. 가장 필요한 단어부터 배운다? x
    // K = 6일때 N-1개의 단어들은 r+{4개의 다른 단어}가 필요해서 r을 배운다고 쳐도 N-1개의 단어는 읽을수가 없음.
    // 나머지 1개의 단어에 필요한 {t}를 배워야 단어를 읽을 수 있음.
    
    // K에 맞게 알파벳 집합을 선택하고 모든 단어에 대해 가능한지 탐색하면서 최대값을 구해봄.
    // O(21C(k-5)*50) 시간 초과? x
    // O(2^(k-5)*50) =10^7을 좀 더 넘는 시간! 
    
    // abcdefghijklmnopqrstuvwxyz
    // 10100000001001000001000000 -> reversed
    int ret = 0;
    if(K < 5)
        ret = 0;// 정답 0 리턴
    else if(K == 26)
        ret = N;
    else
        ret = solve(learn, 5);
        
    cout << ret << endl;
    
}
