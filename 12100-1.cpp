#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// variables
int N;

// functions
vector<vector<int> > update(int dir, vector<vector<int> >& board)
{
	// 게임을 직접해보면 dir 방향에 대해서만 블럭이 합쳐짐을 알 수 있다.
	// 상
	if (dir == 0) {
		for (int x = 0; x < N; x++) {
			// 블럭을 위로 움직임
			vector<int> b1(N, 0);
			int idx = 0;
			for (int y = 0; y < N; y++) {
				if (board[y][x] != 0) {
					b1[idx] = board[y][x];
					idx++;
				}
			}
			//cout << "b1" << endl;
			//for (int i = 0; i < N; i++)
			//	cout << b1[i] << " ";
			//cout << endl;

			// 합칠 수 있다면 갱신함
			vector<int> b2(N, 0);
			vector<bool> v(N, false);
			idx = 0;
			for (int i = 0; i < N - 1; i++) {
				// 0이 나오면 탐색 종료
				if (b1[i] == 0) break;
				// 이미 합쳐진 블럭이면 탐색 x
				if (v[i]) continue;
				if (b1[i] == b1[i + 1]) {
					v[i] = v[i + 1] = true;
					b2[idx] = b1[i] * 2;
					idx++;
				}
				else {
					b2[idx] = b1[i];
					idx++;
					if (i == N - 2)
						b2[idx] = b1[N - 1];
				}
			}
			//cout << "b2" << endl;
			//for (int i = 0; i < N; i++)
			//	cout << b2[i] << " ";
			//cout << endl;
			// b2값을 board로 이동
			for (int i = 0; i < N; i++) {
				board[i][x] = b2[i];
			}
		}
	}
	// 하
	else if (dir == 1) {
		for (int x = 0; x < N; x++) {
			// 블럭을 아래로 움직임
			vector<int> b1(N, 0);
			int idx = 0;
			for (int y = N - 1; y >= 0; y--) {
				if (board[y][x] != 0) {
					b1[idx] = board[y][x];
					idx++;
				}
			}
			//cout << "b1" << endl;
			//for (int i = 0; i < N; i++)
			//	cout << b1[i] << " ";
			//cout << endl;

			// 합칠 수 있다면 갱신함
			vector<int> b2(N, 0);
			vector<bool> v(N, false);
			idx = 0;
			for (int i = 0; i < N - 1; i++) {
				// 0이 나오면 탐색 종료
				if (b1[i] == 0) break;
				// 이미 합쳐진 블럭이면 탐색 x
				if (v[i]) continue;
				if (b1[i] == b1[i + 1]) {
					v[i] = v[i + 1] = true;
					b2[idx] = b1[i] * 2;
					idx++;
				}
				else {
					b2[idx] = b1[i];
					idx++;
					if (i == N - 2)
						b2[idx] = b1[N - 1];
				}
			}
			//cout << "b2" << endl;
			//for (int i = 0; i < N; i++)
			//	cout << b2[i] << " ";
			//cout << endl;
			// b2값을 board로 이동
			for (int i = 0; i < N; i++) {
				board[i][x] = b2[N - i - 1];
			}
		}
	}
	// 좌
	else if (dir == 2) {
		for (int y = 0; y < N; y++) {
			// 블럭을 왼쪽으로 움직임
			vector<int> b1(N, 0);
			int idx = 0;
			for (int x = 0; x < N; x++) {
				if (board[y][x] != 0) {
					b1[idx] = board[y][x];
					idx++;
				}
			}
			cout << "b1" << endl;
			for (int i = 0; i < N; i++)
				cout << b1[i] << " ";
			cout << endl;

			// 합칠 수 있다면 갱신함
			vector<int> b2(N, 0);
			vector<bool> v(N, false);
			idx = 0;
			for (int i = 0; i < N - 1; i++) {
				// 0이 나오면 탐색 종료
				if (b1[i] == 0) break;
				// 이미 합쳐진 블럭이면 탐색 x
				if (v[i]) continue;
				if (b1[i] == b1[i + 1]) {
					v[i] = v[i + 1] = true;
					b2[idx] = b1[i] * 2;
					idx++;
				}
				else {
					b2[idx] = b1[i];
					idx++;
					if (i == N - 2)
						b2[idx] = b1[N - 1];
				}
			}
			cout << "b2" << endl;
			for (int i = 0; i < N; i++)
				cout << b2[i] << " ";
			cout << endl;
			// b2값을 board로 이동
			for (int i = 0; i < N; i++) {
				board[y][i] = b2[i];
			}
		}
	}
	// 우
	else if (dir == 3) {
		for (int y = 0; y < N; y++) {
			// 블럭을 오른쪽으로 움직임
			vector<int> b1(N, 0);
			int idx = 0;
			for (int x = N - 1; x >= 0; x--) {
				if (board[y][x] != 0) {
					b1[idx] = board[y][x];
					idx++;
				}
			}
			cout << "b1" << endl;
			for (int i = 0; i < N; i++)
				cout << b1[i] << " ";
			cout << endl;

			// 합칠 수 있다면 갱신함
			vector<int> b2(N, 0);
			vector<bool> v(N, false);
			idx = 0;
			for (int i = 0; i < N - 1; i++) {
				// 0이 나오면 탐색 종료
				if (b1[i] == 0) break;
				// 이미 합쳐진 블럭이면 탐색 x
				if (v[i]) continue;
				if (b1[i] == b1[i + 1]) {
					v[i] = v[i + 1] = true;
					b2[idx] = b1[i] * 2;
					idx++;
				}
				else {
					b2[idx] = b1[i];
					idx++;
					if (i == N - 2)
						b2[idx] = b1[N - 1];
				}
			}
			cout << "b2" << endl;
			for (int i = 0; i < N; i++)
				cout << b2[i] << " ";
			cout << endl;
			// b2값을 board로 이동
			for (int i = 0; i < N; i++) {
				board[y][i] = b2[N - i - 1];
			}
		}
	}

	return board;
}

int game(int dir, int d, vector<vector<int> >& board)
{
	cout << "함수 " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	// dir 상하좌우에 따라 보드판 갱신
	board = update(dir, board);
	cout << "갱신 후 " << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	// 더 움직였을 때 정답이 감소하는 일은 발생하지 않으므로 depth가 5가 됐을 때 정답을 리턴
	if (d == 5) {
		int ret = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret = max(ret, board[i][j]);
			}
		}
		return ret;
	}
	int ret = 0;
	for (int i = 0; i < 4; i++)
		ret = max(ret, game(i, d + 1, board));

	return ret;
}
int main()
{
	freopen("input.txt", "r", stdin);
	// input
	cin >> N;

	vector<vector<int> > board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	// algorithm
	// 보드판을 상하좌우 방향으로 최대 5번 움직일 수 있음.
	// 같은 값을 갖는 블럭끼리 충돌하면 하나로 합쳐짐.
	// 한 번의 이동에서 합쳐진 블록은 더 합쳐질 수 없음.(다음 턴에는 가능)
	int ret = 0;
	ret = game(-1, 0, board);
	cout << ret << endl;
	return 0;
}
