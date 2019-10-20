#include <iostream>
using namespace std;

// variables
int N, M;
int r, c, d;
int a[50][50];
// 북동남서 기준
int dy[4][4] = {
	  {0, 1, 0, -1}
	, {-1, 0, 1, 0}
	, {0, -1, 0, 1}
	, {1, 0, -1, 0}
};
int dx[4][4] = {
	 { -1, 0, 1, 0 }
	,{ 0, -1, 0, 1 }
	,{ 1, 0, -1, 0 }
	,{ 0, 1, 0, -1 }
};


int main()
{
	//freopen("input.txt", "r", stdin);
	// input
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	// output
	/*
	cout << N << " " << M << endl;
	cout << r << " " << c << " " << d << endl;
	 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	*/

	// d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽
	// d : 북(0), 동(1), 남(2), 서(3)
	// algorithm
	// 청소기가 청소하는 칸의 개수를 출력
	//  1. 현재 위치를 청소한다.
	//	2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
	//		1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
	//		2. 왼쪽 방향에 청소할 방향이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
	//		3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
	//		4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
	//	로봇 청소기는 이미 청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다.
	int y = r;
	int x = c;

	while (1) {
		// 현재 위치를 청소(2)
		//cout << "청소! : " << y << ", " << x << endl;
		//cout << "d : " << d << endl;
		a[y][x] = 2;
		bool canGo = false;
		// 현재 방향을 기준으로 왼쪽 방향부터 차례대로 탐색을 진행
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[d][i];
			int nx = x + dx[d][i];
			// 외곽일 경우 skip
			if (!((0 <= ny && ny < N) && (0 <= nx && nx < M))) continue;
			// 청소할 공간을 발견!
			if (a[ny][nx] == 0) {
				// 북동남서
				// d를 먼저 매핑해야함.
				if (ny - y == -1) d = 0;
				if (nx - x == 1) d = 1;
				if (ny - y == 1) d = 2;
				if (nx - x == -1) d = 3;
				y = ny;
				x = nx;		
				
				canGo = true;
				break;
			}
		}

		if (!canGo) {
			// 바라보는 방향을 유지한채로 한칸 후진!
			int ny = y + dy[d][1];
			int nx = x + dx[d][1];
			
			// 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
			if ( a[ny][nx] == 1 || !((0 <= ny && ny < N) && (0 <= nx && nx < M)) ) break;

			y = ny;
			x = nx;
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 2) ret++;
		}
	}
	cout << ret << endl;

	return 0;
}
