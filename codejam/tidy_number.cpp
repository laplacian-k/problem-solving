#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// variables
long long N;

// functions
long long go(long long cur, int last)
{
	if(cur > N) return -1;
	
	long long ret = cur;
	for(int i = last; i < 10; i++) {
		ret = max(ret, go(cur*10+i, i));
	}
	
	return ret;
}
int main() {
	int tests;
	cin >> tests;
	
	for(int t = 1; t <= tests; t++) {
		// input
		cin >> N;
		
		// algorithm
		long long ret = -1;
		ret = go(0, 1);
		
		cout << "CASE #" << t << ": " << ret << endl;
	}
	return 0;
}
