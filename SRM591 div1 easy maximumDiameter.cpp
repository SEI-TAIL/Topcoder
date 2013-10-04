#include <iostream>
#include <vector>

using namespace std;

class TheTree {
public:
	int maximumDiameter (vector<int> cnt) {
		vector<pair<int, int>> tree;
		int answer = 0;
		for (int i = 0; i < cnt.size(); i++) {
			tree.push_back(make_pair(cnt[i]/2, (cnt[i]+1)/2));
		}
		
		for (int j = 0; j < cnt.size(); j++) {
			int leftLength = 0;
			bool leftFlg = true;
			int rightLength = 0;
			for (int i = j; i < cnt.size(); i++) {
				if (tree[i].first == 0 && leftFlg) {
					leftFlg = false;
				} else if (leftFlg) {
					leftLength++;
				}
				if (tree[i].second == 0) {
					rightLength = 0;
				} else {
					rightLength++;
				}
			}
			if (answer < leftLength + rightLength) {
				answer = leftLength + rightLength;
			}
		}
		return answer;
	}
};