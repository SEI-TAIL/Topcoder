#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LittleElephantAndBooks {
public:
	int getNumber(vector <int> pages, int number) {
		int answer = 0;
		sort(pages.begin(), pages.end());
		for (int i = 0; i < number-1; i++) {
			answer += pages[i];
		}
		answer += pages[number];
		return answer;
	}
};