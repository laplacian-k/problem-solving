#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// variables
int k;
string sign[9];
string ret1;    // 최대정수
string ret2;    // 최소정수
bool used[10];

// functions
void go(int cur, string val)
{
    int d = val.length();
    cout << cur << " " << val << endl;
    //cout << "d : " << d << endl;
    // k+1개의 숫자를 다 만들었다면
    if(d == k+1) {
        cout << "숫자 완성" << endl;
        cout << val << endl;
        long long ans1 = stoll(ret1);
        long long ans2 = stoll(ret2);
        long long v = stoll(val);
        if(ans1 < v) ret1 = val;
        if(ans2 > v) ret2 = val;
        
        return;
    }
    
    for(int next = 0; next < 10; next++) {
        // 사용한 숫자라면 skip
        if(used[next]) continue;
        cout << "기호!" <<endl;
        cout << sign[d-1] << endl;
        used[next] = true;
        if(sign[d-1] == "<" && (cur < next))
            go(next, val+to_string(next));
        if(sign[d-1] == ">" && (cur > next))
            go(next, val+to_string(next));
        used[next] = false;
    }
    
    return;
}

int main()
{
    // init
    ret1 = "0";    // 최대값
    ret2 = "10000000000";    // 최소값
    for(int i = 0; i < 10; i++)
        used[i] = false;
    
    // input
    cin >> k;
    for(int i = 0; i < k; i ++) {
        cin >> sign[k];
    }
    /*
    cout << k << endl;
    for(int i = 0; i < k; i ++) {
        cout << sign[k] << " ";
    }
    cout << endl;
    */
    
    // algorithm
    // k+1개의 숫자를 순서대로 배치하는 문제이므로 O((k+1)!) 걸림. 충분히 구할 수 있음.
    for(int i = 0; i < 10; i++) {
        used[i] = true;
        go(i, to_string(i));
        used[i] = false;
    }        
    
    cout << ret1 << endl;
    cout << ret2 << endl;
    return 0;
}
