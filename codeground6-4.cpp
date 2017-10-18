#include <iostream>
#include <string>
using namespace std;

// variables
int N, K;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
long long d[200000];

int main(int argc, char** argv)
{
	int T, test_case;
    //freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		// input
		cin >> N >> K;
		string path;
		cin >> path;

		// algorithm
		// 각 대각선의 대표값(끝점)을 구해둠.
		d[0] = 0;
		for (int i = 1; i <= N; i++) {
			d[i] = d[i - 1] + i;
		}
		for (int i = 1; i <= N - 1; i++) {
			d[i + N] = d[i + N - 1] + (N - i);
		}

		// 움직이면서 방번호를 더해나감.
		// 좌표의 대각선 번호를 구하고
		// 우상향 증가, 좌하향 증가 대각선에 따라 점수를 구한다.
		long long ret = 1;
		long long y = 0;
		long long x = 0;
		for (int i = 0; i < K; i++) {
			if (path[i] == 'U') { y += dy[0]; x += dx[0]; }
			else if (path[i] == 'D') { y += dy[1]; x += dx[1]; }
			else if (path[i] == 'L') { y += dy[2]; x += dx[2]; }
			else if (path[i] == 'R') { y += dy[3]; x += dx[3]; }

			// y+x+1은 대각선 번호
			long long base = d[y + x + 1];

			// 홀수 대각선은 우상향, 짝수 대각선은 좌하향
			// 윗 삼각형(N번째 대각선 포함)과 아랫 삼각형의 계산법이 다름.
			bool odd = ((y + x + 1) & 1) ? true : false;
			bool up = (y + x < N) ? true : false;

			long long n;
			// 대표값에서 y만큼 빼줌.
			if (odd && up)
				n = (base - y);
			// 대표값에서 (N-1-x)만큼 빼줌.
			if (odd && !up)
				n = (base - (N-1-x));
			// 대표값에서 x만큼 빼줌.
			if (!odd && up)
				n = (base - x);
			// 대표값에서 (N-1-y)만큼 빼줌.
			if (!odd && !up)
				n = (base - (N-1-y));

			ret += n;
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << ret << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
