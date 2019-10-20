#include <iostream>
#include <string>
#include <vector>
using namespace std;

// variables
int N;
string room[1000];

// 다음 방의 from을 구함
const int to[3][4] = {
	// 방없음
	{0, 1, 2, 3},
	// (/) 모양의 거울
	{3, 2, 1, 0},
	// (\) 모양의 거울
	{2, 3, 0, 1}
};
const int dy[4] = { 1, -1, 0,  0 };
const int dx[4] = { 0,  0, 1, -1 };

bool d[1000][1000];

//functions
void go()
{
	// (0, 0) 왼쪽방향에서 빛이 들어옴
	int y = 0;
	int x = 0;
	int from = 2;
	while (0 <= y && y < N && 0 <= x && x < N)
	{
		int roomType = (room[y][x]-'0');
		if (roomType != 0) d[y][x] = true;
		from = to[roomType][from];
		x += dx[from];
		y += dy[from];
		
	}
}
int main(int argc, char** argv)
{
	int T, test_case;
	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		// input
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> room[i];
			// init
			for (int j = 0; j < N; j++) {
				d[i][j] = false;
			}
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int roomType = (room[i][j] - '0');
				cout << roomType << " ";
			}			
			cout << endl;
		}
		*/

		// algorithm
		int ret = 0;
		go();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (d[i][j]) ret++;
			}
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << ret << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
