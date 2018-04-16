#include <iostream>
#include <string>
#include <vector>
using namespace std;

// variables
int R, C, H, V;
string w[100];

// functions
bool go(int h, int v)
{
	// searching for 4 directions
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum4 = 0;
	
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			
			if(w[i][j] == '@') {
				if(i < h && j < v) sum1 += 1;
				if(i < h && j >= v) sum2 += 1;
				if(i >= h && j < v) sum3 += 1;
				if(i >= h && j <= v) sum4 += 1;
			}
		}
	}
	
	//cout << sum1 << ", " << sum2 << ", " << sum3 << ", " << sum4 << "\n";
	if(sum1 == sum2 && sum1 == sum3 && sum1 == sum4) return true;
	else return false;
	
}
int main() {
	int tests;
	cin >> tests;
	
	for(int t = 1; t <= tests; t++) {
		// input
		cin >> R >> C >> H >> V;
		for(int i = 0; i < R; i++) {
			cin >> w[i];
		}
		
		// algorithm
		
		vector<pair<int, int> > gen;
		for(int h = 1; h <= R-1; h++) {
			for(int v = 1; v <= C-1; v++) {
				gen.push_back(make_pair(h, v));
			}
		}
		
		bool ret = false;
		for(int i = 0; i < gen.size(); i++) {
			//cout << "gen ";
			int h = gen[i].first;
			int v = gen[i].second;
			//cout << h << ", " << v << endl;
			ret = go(h, v);
			if(ret) break;
		}
		
		cout << "Case #" << t << ": ";
		if(ret) cout << "POSSIBLE" << "\n";
		else    cout << "IMPOSSIBLE" << "\n";
	}
	return 0;
}
