#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// variables
int n;
int m[500][500];
int dy[] = { -1, 1, 0 , 0 };
int dx[] = { 0 , 0, -1, 1 };
int cache[500][500];
// functions
// y, x로부터 최대한 움직일 수 있는 거리를 계산!
int go(int y, int x)
{
	//cout << "y : " << y << ", " << "x : " << x << endl;

	int& ans = cache[y][x];
	if (ans != -1) return ans;

	int ret = 1;	// 아무 곳도 갈 수 없다면 살 수 있는 일수는 1일이다.
	int temp = m[y][x];

	for (int i = 0; i < 4; i++) {


		int ny = y + dy[i];
		int nx = x + dx[i];

		//cout << ny << ", " << nx << endl;

		// 범위를 벗어난 곳
		if (!((0 <= ny && ny < n) && (0 <= nx && nx < n))) continue;
		// 이미 먹어치운 곳
		//if (m[ny][nx] == 0) continue;
		// 먹이가 더 적은 곳
		if (m[y][x] >= m[ny][nx]) continue;

		// 대나무를 먹어 치움
		//m[y][x] = 0;
		ret = max(ret, 1 + go(ny, nx));
		// 원복
		//m[y][x] = temp;
	}

	return ans = ret;
}
int main()
{
	// init
	memset(cache, -1, sizeof(cache));
	//freopen("input.txt", "r", stdin);
	// input
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	// algorithm
	// 항상 현재보다 숲이 많은 쪽으로 이동(많은 곳이 없다면 그 자리에서 die)
	// 움직일 공간이 없을 때까지 이동! 최대한 살 수 있는 일수를 계산한다!
	// 메모이제이션 사용!(중복 계산이 상당히 많음!)
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << "go" << "(" << i << ", " << j << ")" << go(i, j) << endl;
			//ret = max(ret, 1 + go(i, j));
			ret = max(ret, go(i, j));
		}
	}

	cout << ret << endl;
}
