#include <iostream>
#include <string>
using namespace std;

// variables
int N;
int d[1001];

// functions
char get_prev(char cur)
{
    if(cur == 'B')
        return 'J';
    else if(cur == 'O')
        return 'B';
    else if(cur == 'J')
        return 'O';
}

int main()
{
    // input
    cin >> N;
    string s;
    cin >> s;
    
    cout << N << endl;
    cout << s << endl;
    
    // init
    for(int i = 0; i <= 1000; i++) {
        d[i] = -1;
    }
    
    // algorithm
    // d[n] : n까지 가는데 필요한 에너지의 최소값
    // d[j] = min(d[j], d[i] + (j-i)^2) (i는 j 이전에 밟아야하는 문자가 존재하는 위치) 
    
    d[0] = 0;
    //d[1] = 0;
    /*
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {            
            d[i] = min(d[i], d[j]+(i-j)*(i-j));
        }
    }
    */
    for(int j = 1; j < N; j++) {
        for(int i = 0; i < j; i++) {
            // 갈 수 없다면 skip
            if(d[i] == -1) continue;
            // s[i]가 s[j] 이전에 밟아야하는 문자가 아니라면 skip
            // cout << s[j] << endl;
            //cout << get_prev(s[j]) << endl;
            if(get_prev(s[j]) != s[i]) continue;
            
            int cost = d[i]+(j-i)*(j-i);
            // 내가 뒤에 위치한 d[x]를 다 구해놨다면 정답이 도출된다.
            // d[j]가 계산되지 않았거나 최소가 갱신될 경우만 계산
            if(d[j] == -1 || d[j] > cost)
                d[j] = cost;
        }
    }
    
    cout << d[N-1] << endl;
    return 0;
}
