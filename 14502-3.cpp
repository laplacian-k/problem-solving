#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// variables
int N, M;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
// functions

// 바이러스를 퍼트리는 함수
void virus(int y, int x, vector<vector<int> >& b)
{
	// 상하좌우를 탐색
	// lab의 상태는 공유됨.
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if ((0 <= ny && ny < N && 0 <= nx && nx < M) && b[ny][nx] == 0) {
			b[ny][nx] = 2;
			virus(ny, nx, b);
		}
	}
}
// 안전영역의 크기를 구하는 함수
// 0은 빈 칸, 1은 벽, 2는 바이러스
int go(int y, int x, int d, vector<vector<int> >& lab)
{
	// 벽을 3개 고르면 정답을 return
	if (d == 3) {
		vector<vector<int> > b = lab;
		// 바이러스를 기준으로 영역을 채움
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (b[i][j] == 2) {
					virus(i, j, b);
				}
			}
		}

		int ret = 0;
		// 안전영역(0)의 개수를 구함
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (b[i][j] == 0) ret++;
			}
		}
		return ret;
	}
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((i > y || (i == y && j >= x)) && lab[i][j] == 0) {
				lab[i][j] = 1;
				ret = max(ret, go(i, j, d + 1, lab));
				lab[i][j] = 0;
			}
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	// input
	cin >> N >> M;
	vector<vector<int> > lab(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
		}
	}

	// algorithm
	int ret = 0;
	ret = go(0, 0, 0, lab);
	cout << ret << endl;
}
