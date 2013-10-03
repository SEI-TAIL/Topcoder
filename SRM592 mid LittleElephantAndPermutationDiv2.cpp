#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class LittleElephantAndPermutationDiv2 {
public:
	long long getNumber(int N, int K) {
		vector<int> permuA;
		long long ans = 0;
		for (int i = 1; i <= N; i++) {
			permuA.push_back(i);
		}
		vector<int> permuB(permuA);
		do {
			int tmpAns = 0;
			for (int i = 1; i <= N; i++) {
				tmpAns += max(permuA[i-1], permuB[i-1]);
			}
			if (tmpAns >= K) {
				ans++;
			}
		} while (next_permutation(permuB.begin(), permuB.end()));
		long long permuNum = 1;
		for (int i = 1; i <= N; i++) {
			permuNum *= i;
		}
		ans *= permuNum;
		return ans;
	}
};