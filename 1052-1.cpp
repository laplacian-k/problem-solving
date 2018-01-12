#include <iostream>
#include <queue>
#include <map>
using namespace std;

// variables
int N, K;
int bowl[10000001];

int main()
{
    // input
    cin >> N >> K;
    
    // algorithm
    // map(리터, 개수)
    queue<map<int, int> > q;
    map<int, int> state = m;
    m[1] = N;
    q.push(m);
    
    while(!q.empty()) {
        map<int, int> cur = q.front();
        q.pop();
        
        map<int, int> next = cur;
        // 키별로 순회하면서 count가 1보다 크다면
        for(int i = 0; i < next.size(); i++) {
            if(next[i].count > 1) {
                next[i] = next[i] - 1;
                
                if(next.count(2*i) == 0) next[2*i] = 1;
                else next[2*i] += 1;
            }
            
            // 물이 들어있는 물병의 개수가 K 초과라면 queue에 push
            // 키별로 순회하면서 sum을 함
            int sum = 0;
            for(int i = 0; i < next.size(); i++) {
                sum += next[i];
            }
            
            if(sum > K) {
                q.push(next);
                dist[][] = dist[][] + 1;
            }
        }       
    }
    
    // 리터, 개수의 최소값
    cout << dist[]
    return 0;    
}
