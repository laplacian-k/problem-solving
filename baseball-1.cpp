#define N 4



typedef struct {

	int strike;

	int ball;

} Result;



// API

extern Result query(int guess[]);



void doUserImplementation(int guess[]) {

	// algorithm

	// init
	int strike = -1;
	int ball = -1;
	int number[5040];
	int temp = -1;
	int prev_strike = -1;
	int prev_ball = -1;

	bool canUse[10][4];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			canUse[i][j] = true;
		}
	}

	const int base[] = { 1000, 100, 10, 1 };

	bool visit[10];
	for (int i = 0; i < 10; i++) {
		visit[i] = false;
	}

	// 숫자 생성
	int idx = 0;
	for (int a = 0; a < 10; a++) {
		if (visit[a]) continue;
		visit[a] = true;

		for (int b = 0; b < 10; b++) {
			if (visit[b]) continue;
			visit[b] = true;

			for (int c = 0; c < 10; c++) {
				if (visit[c]) continue;
				visit[c] = true;

				for (int d = 0; d < 10; d++) {
					if (visit[d]) continue;
					visit[d] = true;

					number[idx] = a * 1000 + b * 100 + c * 10 + d * 1;
					//cout << number[idx] << endl;
					idx++;


					visit[d] = false;
				}
				visit[c] = false;
			}
			visit[b] = false;
		}
		visit[a] = false;
	}



	// brute-force
	// guess 생성
	// 0123 ~ 9876	
	for (int i = 0; i < 5040; i++) {
		//cout << number[i] << endl;
		bool canGo = true;

		// 네자리 추측하는 수 생성	
		for (int j = 0; j < 4; j++) {
			guess[j] = (number[i] / base[j]) % 10;

			// j번째 자리에 guess[j]가 불가능하다면
			if (!canUse[guess[j]][j]) canGo = false;
		}

		if (!canGo) continue;

		// canUse 출력
		
		//cout << "canUse 배열 출력" << endl;

		for (int n = 0; n < 10; n++) {
			for (int m = 0; m < 4; m++) {
				//cout << canUse[n][m] << " ";
			}
			//cout << endl;
		}
		
		//cout << number[i] << " ";

		// query 함수 실행
		Result ret = query(guess);
		int strike = ret.strike;
		int ball = ret.ball;

		//cout << strike << ", " << ball << endl;
		// strike와 ball 개수에 따라 추측하는 수를 판단하는 알고리즘

		// 스트라이크+볼이 4라면 해당 숫자를 제외한 숫자들은 사용 불가능!
		if (strike + ball == 4) {
			//cout << "발견1! " << number[i] << endl;

			for (int n = 0; n < 10; n++) {
				bool canSkip = false;
				for (int m = 0; m < 4; m++) {
					if (n == guess[m]) canSkip = true;
				}

				if (canSkip) continue;

				for (int k = 0; k < 4; k++) {
					canUse[n][k] = false;
				}
			}

		}

		// 스트라이크가 0개라면 해당 자리에 guess[j] 사용 불가능
		if (strike == 0) {
			for (int n = 0; n < 4; n++) {
				canUse[guess[n]][n] = false;
			}
		}

		// 스트라이크+볼이 0이라면 현재 생성한 숫자들은 사용할 수 없음
		if (strike + ball == 0) {
			//cout << "발견2! " << number[i] << endl;
			for (int n = 0; n < 4; n++) {
				for (int m = 0; m < 4; m++) {
					canUse[guess[n]][m] = false;
				}
			}
		}

		// prev_strike <= cur_strike일 경우, 그대로인 숫자가 cur_strike이하라면 그 숫자는 확정
		//cout << "prev : " << temp << ", cur : " << number[i] << endl;
		if (temp != -1) {
			int num_diff = 0;
			int s_diff = strike - prev_strike;
			int b_diff = ball - prev_ball;
			for (int n = 0; n < 4; n++) {
				int prev = (temp / base[n]) % 10;
				int cur = (number[i] / base[n]) % 10;
				if (prev != cur) num_diff++;
			}
			//cout << num_diff << ", " << s_diff << ", " << b_diff << endl;

			// 스트라이크만 변했을 경우
			if (s_diff != 0 && b_diff == 0) {
				// 바뀐 숫자 개수로 비교
				if (s_diff > 0 && (s_diff == num_diff)) {
					// cur에 바뀐 숫자는 그 자리에 반드시 사용되야 함.
					for (int n = 0; n < 4; n++) {
						int p = (temp / base[n]) % 10;
						int c = (number[i] / base[n]) % 10;
						if (p != c) {
							for (int m = 0; m < 10; m++) {
								// cur과 같은 숫자는 skip
								if (m == c) continue;
								canUse[m][n] = false;
							}
							
						}
					}
				}
				if (s_diff < 0 && (-s_diff == num_diff)) {
					// prev에 쓰였던 숫자들은 그 자리에 반드시 사용되야 함.
					for (int n = 0; n < 4; n++) {
						int p = (temp / base[n]) % 10;
						int c = (number[i] / base[n]) % 10;
						if (p != c) {
							for (int m = 0; m < 10; m++) {
								// prev와 같은 숫자는 skip
								if (m == p) continue;
								canUse[m][n] = false;
							}

						}
					}
				}
			}

			// 볼만 변했을 경우
			if (s_diff == 0 && b_diff != 0) {
				// 바뀐 숫자 개수로 비교
				if (b_diff > 0 && (b_diff == num_diff)) {
					// prev에 사용했던 숫자는 사용할 수 없음!
					for (int n = 0; n < 4; n++) {
						int p = (temp / base[n]) % 10;
						int c = (number[i] / base[n]) % 10;
						if (p != c) {
							for (int m = 0; m < 4; m++) {
								canUse[p][m] = false;
							}

						}
					}
				}
				if (b_diff < 0 && (-b_diff == num_diff)) {
					// cur에 사용한 숫자는 사용할 수 없음!
					for (int n = 0; n < 4; n++) {
						int p = (temp / base[n]) % 10;
						int c = (number[i] / base[n]) % 10;
						if (p != c) {
							for (int m = 0; m < 4; m++) {
								canUse[c][m] = false;
							}

						}
					}
				}
			}

			// 1개를 바꿨는데 스트라이크가 바뀌었을 경우
			if (num_diff == 1) {
				// 스트라이크 증가. 해당 자리에 cur이외의 것들은 불가
				if (s_diff == 1) {
					for (int n = 0; n < 4; n++) {
						int p = (temp / base[n]) % 10;
						int c = (number[i] / base[n]) % 10;
						if (p != c) {
							for (int m = 0; m < 10; m++) {
								if (m == c) continue;
								canUse[m][n] = false;
							}
						}
					}
				}

				if (s_diff == -1) {
					for (int n = 0; n < 4; n++) {
						int p = (temp / base[n]) % 10;
						int c = (number[i] / base[n]) % 10;
						if (p != c) {
							for (int m = 0; m < 10; m++) {
								if (m == p) continue;
								canUse[m][n] = false;
							}
						}
					}
				}
			}
		}


		temp = number[i];
		prev_strike = strike;
		prev_ball = ball;
		//cout << "스트라이크?" << strike << endl;
		if (strike == 4) break;
	}


}
