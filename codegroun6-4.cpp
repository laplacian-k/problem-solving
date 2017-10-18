#include <iostream>
#include <string>
using namespace std;

// variables
int N, K;


int main(int argc, char** argv)
{
	int T, test_case;
	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        // input
        cin >> N >> K;
        string input;
        cin >> input;
        
        // algorithm
        long long ret = 0;
        // 움직이면서 방번호를 더해나감.
        int y = 0;
        int x = 0;
        for(int i = 0; i < K; i++) {
            cout << input[i] << endl;
        }
		cout << "Case #" << test_case+1 << endl;
		//cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
