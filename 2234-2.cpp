#include <iostream>
#include <algorithm>
using namespace std;

// variables
int n, m;
int w[50][50];
int idx;
const int dy[] = { 0, -1, 0, 1 };    // 서북동남
const int dx[] = { -1, 0, 1, 0 };
bool visit[50][50];
int room[50][50];
int s[2500];    // 방은 최대 2500개까지 있을 수 있음.

// functions
// idx번 방의 크기를 구하는 재귀함수
int go(int y, int x)
{
	//cout << y << ", " << x << endl;
	// 방문했음을 표시
	visit[y][x] = true;
	room[y][x] = idx;
	// 벽이 없다면 go
	// 서(1), 북(2), 동(4), 남(8)
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		// 벽이 있을 경우 skip
		if (w[y][x] & (1 << i)) continue;

		int ny = y + dy[i];
		int nx = x + dx[i];
		// 방문했을 경우 skip
		if (visit[ny][nx]) continue;

		// 범위를 벗어날 경우 skip
		if (!((0 <= ny && ny < m) && (0 <= nx && nx < n))) continue;
		
		ret += go(ny, nx);
	}
	
	return ret;
	
}

int main()
{
	freopen("input.txt", "r", stdin);
	// init
	idx = 0;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visit[i][j] = false;
		}
	}
	// input
	cin >> n >> m;
	// m개의 줄에는 n개의 벽의 정보가 제공됨
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	// algorithm
	int ret1 = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 방문한적 있다면 실행 x
			if (visit[i][j]) continue;
			s[idx] = go(i, j);
			idx++;
		}
	}
	ret1 = idx;

	int ret2 = 0;
	
	for (int i = 0; i < idx; i++) {
		//cout << s[i] << endl;
		ret2 = max(ret2, s[i]);
	}

	int ret3 = 0;
	// 벽을 하나 없애서 만들 수 있는 가장 큰 방의 크기를 구함.
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			for (int i = 0; i < 4; i++) {
				// 벽이 있다면 현재 방과 다음 방을 구함
				if (w[y][x] & (1 << i)) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					// 범위를 벗어나면 계산하지 않음
					if (!((0 <= ny && ny < m) && (0 <= nx && nx < n))) continue;
					// 방 번호가 같다면 계산하지 않음
					if (room[y][x] == room[ny][nx]) continue;
					// 최대 방 크기를 구함.
					ret3 = max(ret3, s[room[y][x]] + s[room[ny][nx]]);
				}
			}
			
		}
	}
	cout << ret1 << endl;
	cout << ret2 << endl;
	cout << ret3 << endl;
	
	return 0;
}
