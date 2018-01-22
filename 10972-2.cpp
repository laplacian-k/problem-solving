#include <iostream>
#include <vector>
//#include <algorithm>    // for next_permutation
using namespace std;

// variables
int N;

// functions
bool next_permutation(vector<int> &a, int n)
{
    int i = n-1;    // 마지막 인덱스로 초기화
    // 인덱스가 0 초과, a[i-1]이 더 크다면 계속 i를 감소시킨다.
    // 즉, a[i-1] < a[i]를 만족하는 가장 큰 i를 찾는다.
    while(i > 0 && a[i-1] >= a[i]) {
        i -= 1;
    }
    if(i <= 0) return false;    // 마지막 순열이라면 false 리턴
    
    int j = n-1;    // 마지막 인덱스로 초기화
    // a[i-1]보다 큰 a[j]를 찾는다. 가장 큰 j여야 한다.
    while(a[j] <= a[i-1]) {
        j -= 1;
    }
    
    // 자리 변경
    swap(a[i-1], a[j]);
    j = n-1;
    // a[i]부터 순열을 뒤집음
    while(i < j) {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main()
{
    // input
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // algorithm
    if(next_permutation(a, N)) {
        for(int i = 0; i < N; i++) {
            cout << a[i] << ' ';    
        }        
    }
    else {
        cout << -1 << endl;
    }
    cout << endl;
    
    return 0;
}
