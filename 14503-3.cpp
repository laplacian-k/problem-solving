#include <iostream>
using namespace std;

// variables
int N, M;
int r, c;
int d;
int a[50][50];
const int left[4][4] = {};

int main()
{
	// input
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}

	// algorithm
	// 빈칸(0) 벽(1) 청소한 공간(2)
	// 로봇이 바라보는 방향 북(0) 동(1) 남(2) 서(3)
	// 지금 바라보고 있는 방향 기준 왼쪽방향부터 차례대로 탐색. (앞을 보고있다면 앞을 본 상태에서 왼쪽을 탐색)
	
	int cur = d;

	
	//int ret = 0;
	//ret = go();
	//cout << ret << endl;
}
