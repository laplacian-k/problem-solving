#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// variables
int N;

// functions
vector<int> update(int type, int x, vector<int> board)
{
	// 흑돌이라면
	if (type == 1) {
		board[x] = 2;
		// 돌을 둔 위치로부터 왼쪽, 오른쪽의 흰돌을 뒤집음
		// 1. 검은돌을 만나면 그 사이의 흰돌을 뒤집고
		// 2. 벽을 만날때까지 모두 흰돌이라면 모든 흰돌을 뒤집음
		vector<int> left;
		bool canReverse = true;
		for (int i = x-1; i >= 0; i--) {
			if (board[i] == 1) left.push_back(i);
			// 빈칸을 만났다면 무효
			if (board[i] == 0) {
				canReverse = false;
				break;
			}
			// 흑돌을 만났다면 탐색 끝남
			if (board[i] == 2) break;
		}

		if (canReverse) {
			for (int j = 0; j < left.size(); j++) {
				board[left[j]] = 2;
			}
		}		
		
		vector<int> right;
		canReverse = true;
		for (int i = x + 1; i < N; i++) {
			if (board[i] == 1) right.push_back(i);
			// 빈칸을 만났다면 무효
			if (board[i] == 0) {
				canReverse = false;
				break;
			}
			// 흑돌을 만났다면 탐색 끝남
			if (board[i] == 2) break;
		}

		if (canReverse) {
			for (int j = 0; j < right.size(); j++) {
				board[right[j]] = 2;
			}
		}

	}
	// 흰돌이라면
	else if (type == 0)	{
		board[x] = 1;

		// 돌을 둔 위치로부터 왼쪽, 오른쪽의 검은돌을 뒤집음
		// 1. 흰돌을 만나면 그 사이의 검은돌을 뒤집고
		// 2. 벽을 만날때까지 모두 검은돌이라면 모든 검은돌을 뒤집음
		vector<int> left;
		bool canReverse = true;
		for (int i = x - 1; i >= 0; i--) {
			if (board[i] == 2) left.push_back(i);
			// 빈칸을 만났다면 무효
			if (board[i] == 0) {
				canReverse = false;
				break;
			}
			// 흰돌을 만났다면 탐색 끝남
			if (board[i] == 1) break;
		}

		if (canReverse) {
			for (int j = 0; j < left.size(); j++) {
				board[left[j]] = 1;
			}
		}

		vector<int> right;
		canReverse = true;
		for (int i = x + 1; i < N; i++) {
			if (board[i] == 2) right.push_back(i);
			// 빈칸을 만났다면 무효
			if (board[i] == 0) {
				canReverse = false;
				break;
			}
			// 흰돌을 만났다면 탐색 끝남
			if (board[i] == 1) break;
		}

		if (canReverse) {
			for (int j = 0; j < right.size(); j++) {
				board[right[j]] = 1;
			}
		}
	}

	return board;
}

int game(int type, int d, vector<int>& board)
{
	cout << type << " " << d << " " << endl;
	// depth가 3보다 커질 때 정답 판단
	if (d > 3) {
		int ret = 0;
		for (int i = 0; i < N; i++)
			// 흑돌이라면 1점씩 더함.
			if (board[i] == 2) ret++;
		return ret;
	}
	// 둘 곳이 없다면 지금 보드판으로 점수를 계산
	bool isFull = true;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (board[i] == 0) {
			isFull = false;
			break;
		}
		if (board[i] == 2) ans++;
	}
	if (isFull) return ans;

	int ret = 0;
	for (int i = 0; i < N; i++) {
		// 빈칸이 아니라면 skip
		if (board[i] != 0) continue;

		// 바둑알을 둠(보드판 갱신)
		vector<int> b = update(type, i, board);

		// type XOR 1 : type이 0이라면 1, type이 1이라면 0
		ret = max(ret, game((type^1), d + 1, b));

		// 흰돌이라면 가장 왼쪽 위치를 찾고 끝냄
		if (type == 0) break;

	}

	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	// input
	cin >> N;
	vector<int> board(N);
	for (int i = 0; i < N; i++)
		cin >> board[i];

	// algorithm
	int ret = 0;
	ret = game(1, 1, board);
	cout << ret << endl;

	return 0;
}
