#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
// 벡터를 재귀를 돌려서 이어지는지 아니면 원복되는지 확인
void test(vector<vector<int> >& a, int d)
{
	cout << d << endl;
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	if(d == 2) {cout << "끝" << endl; return;}
	
	for(int i = 0; i < 2; i++){
		a[i][0] = cnt;
		cnt++;
		test(a, d+1);
	}
}

int main() {
	vector<vector<int> > a(2, vector<int>(2, 1));
	test(a, 0);
	return 0;
}
