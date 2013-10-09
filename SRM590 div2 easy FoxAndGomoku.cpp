#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class FoxAndGomoku {
public:
	string win(vector<string> board) {
		FOR(x, 0, board.size()) {
			FOR(y, 0, board.size()) {
				if (board[y][x] == 'o') {
					bool rowFlg = true;
					bool colFlg = true;
					bool diaFlg = true;
					bool revDiaFlg = true;
					int roopNum = 0;
					int revRoopNum = 0;
					for (int row = 0, col = 0; row < board.size()-x && col < board.size()-y; row++, col++) {
						if (board[y][x+row] == '.') {
							rowFlg = false;
						}
						if (board[y+col][x] == '.') {
							colFlg = false;
						}
						if (board[y+col][x+row] == '.') {
							diaFlg = false;
						}
						roopNum++;
						if (roopNum == 5) {
							break;
						}
					}
					for (int row = 0, col = 0; row < board.size()-x && col >= y; row++, col--) {
						if (board[y-col][x+row] == '.') {
							revDiaFlg = false;
						}
						revRoopNum++;
						if (revRoopNum == 5) {
							break;
						}
					}
					if (roopNum == 5 && (rowFlg == true || colFlg == true || diaFlg == true)) {
						return "found";
					} else if (revRoopNum == 5 && revDiaFlg == true) {
						return "found";
					}
				}
			}
		}
		return "not found";
	}
};
