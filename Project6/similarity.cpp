#include <vector>
#include <iostream>

using std::vector;

class Similarity {
public:
	int lengthScore(std::string a, std::string b) {
		int score = 0;
		if (a.length() == b.length()) score = 60;
		if (a.length() >= b.length() * 2 || b.length() >= a.length() * 2) score = 0;

		else {
			if (a.length() > b.length()) {
				double gap = (a.length() - b.length()) / b.length();
				score = static_cast<int>((1 - gap) * 60);
			}
			else {
				double gap = b.length() - a.length();
				score = static_cast<int>((1 - gap / a.length()) * 60);

			}
		}
		return score;
	}
};