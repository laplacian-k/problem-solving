#include <iostream>
#include <algorithm>
using namespace std;

// variables
int N, M;
int v[1001][1001];
int cache[1001][1001][3];
const int low = -1000000000;
const int dy[] = { 1, 0, 0 };    // 하, 우, 좌
const int dx[] = { 0, 1, -1};
// functions
int go(int y, int x, int last)
{
	//cout << y << ", " << x << ", " << last << endl;
	int& ans = cache[y][x][last];
	if (ans != low) return ans;
	// 범위를 벗어나면 탐색하지 않음.
	//if (!((1 <= y && y <= N) && (1 <= x && x <= M)))
	//	return 0;
	// N, M에 도착했으면 종료
	if (y == N && x == M) return v[y][x];

	int ret = low;

	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		// 우로 이동은 우에서 왔을 경우 skip
		if (i == 1 && last == 2) continue;
		// 좌로 이동은 좌에서 왔거나 마지막 줄일 경우 skip
		if (i == 2 && (last == 1 || y == N)) continue;
		// 가지치기를 우선 적용해서 TLE를 피한다.
		if (!((1 <= ny && ny <= N) && (1 <= nx && nx <= M))) continue;
		ret = max(ret, v[y][x] + go(ny, nx, i));

	}
	return ans = ret;

}
int main()
{
	// init
	//memset(cache, -1, sizeof(cache));
	// memset으로는 -1 이외의 다른 데이터를 넣을 수 없음.
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			for (int k = 0; k < 3; k++) {
				cache[i][j][k] = low;
			}
		}
	}
	
	// input
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> v[i][j];
		}
	}
	// algorithm
	int ret = 0;
	ret = go(1, 1, 0);
	cout << ret << endl;
}
