#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

// valuables
string pancakes;
int K;

int main() {
	int tests;
	cin >> tests;
	for(int t = 1; t <= tests; t++) {
		
		// input
		cin >> pancakes >> K;
		// output
		// cout << pancakes << ", " << K << endl;
		int N = pancakes.length();
		long long ret = 0;
		for(int i = 0; i < N-K+1; i++) {
			if(pancakes[i] == '+') continue;
			for(int j = 0; j < K; j++) {
				pancakes[i+j] = (pancakes[i+j] == '+') ? '-' : '+';
			}
			ret += 1;
		}
		
		bool ok = true;
		for(int i = 0; i < N; i++) {
			if(pancakes[i] == '-') {
				ok = false;
				break;
			}
		}
		
		if(!ok) {
			cout << "CASE #" << t << ": " << "IMPOSSIBLE" << endl;
		}
		else {
			cout << "CASE #" << t << ": " << ret << endl;		
		}
	
	}
	
	return 0;
}
