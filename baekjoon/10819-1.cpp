#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// variables
int N;
int A[8];

int main()
{
    // input
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // algorithm
    //|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| 의 최대값을 구하라
    // next_permutation 사용
    int ret = 0;
    
    // 오름차순으로 정렬
    sort(A.begin(), A.end());
    
    do {        
        int sum = 0;
        for(int i = 0; i < N-1; i++) {
            if(A[i] >= A[i+1] ) sum += A[i]-A[i+1];
            else sum += A[i+1]-A[i];
        }
        ret = max(ret, sum);
    } while(next_permutation(A.begin(), A.end()));
    
    cout << ret << '\n';
    
    return 0;
}
