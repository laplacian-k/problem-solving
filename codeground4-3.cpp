#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

// variables
int A, B, C, D, E;
int N;
struct dat {
	int y;
	int x;
};
dat d[10000];

const int score[4][10] = {
	{6, 13, 13, 4, 4, 18, 18, 1, 1, 20},
	{11, 14, 14, 9, 9, 12, 12, 5, 5, 20},
	{11, 8, 8, 16, 16, 7, 7, 19, 19, 3},
	{6, 10, 10, 15, 15, 2, 2, 17, 17, 3}
};
const double PI = 3.14;

// functions
int dart(dat d)
{
	// y, x 좌표를 기준으로 몇 점인지 계산!
	int y = d.y;
	int x = d.x;

	int r2 = y*y + x*x;
	// out of board
	if (r2 > E*E) return 0;	

	// single, double, triple, bull 계산
	int m = 1;
	if (r2 < A*A) return 50;
	if (B*B < r2 && r2 < C*C) m = 3;
	if (D*D < r2 && r2 < E*E) m = 2;

	// 어느 영역에 꽂혔는지 계산
	// 360도를 20개의 영역으로 분할 -> 18도씩!
	// 몇사분면?
	// 1 (+, +), 2(+, -), 3(-, -), 4(-, +)
	int ret = 0;

	int n;
	if (y == 0 || x == 0) n = 0;    // 사분면이 정의되지 않는 값.
	if (y > 0 && x > 0) n = 1;
	if (y > 0 && x < 0) n = 2;
	if (y < 0 && x < 0) n = 3;
	if (y < 0 && x > 0) n = 4;	

	if (n == 0) {
		if (x == 0 && y > 0) return m * 20;
		if (x == 0 && y < 0) return m * 3;
		if (y == 0 && x > 0) return m * 6;
		if (y == 0 && x < 0) return m * 11;
	}
	// 기울기가 어느 영역에 속하나?
	// tan(theta) = y/x
	// theta = atan(y/x);
	double a = abs(y) / (double)abs(x);
	double theta = (atan(a) * 180) / PI;
	int k = theta / 9;
	ret = score[n-1][k];

	return m*ret;
}
int main(int argc, char** argv)
{
	int T, test_case;
    // freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		// input
		cin >> A >> B >> C >> D >> E;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> d[i].x >> d[i].y;
		}

		// algorithm
		int ret = 0;
		for (int i = 0; i < N; i++) {
			ret += dart(d[i]);
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << ret << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
